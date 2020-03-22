package pkglint

import (
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
	"strings"
)

// Path is a slash-separated path.
// It may or may not resolve to an existing file.
// It may be absolute or relative.
// Some paths may contain placeholders like @VAR@ or ${VAR}.
// The base directory of relative paths is unspecified.
type Path string

func NewPath(p string) Path { return Path(p) }

func (p Path) String() string { return string(p) }

func (p Path) GoString() string { return sprintf("%q", string(p)) }

// IsEmpty returns true if the path is completely empty,
// which is usually a sign of an uninitialized variable.
func (p Path) IsEmpty() bool { return p == "" }

// Returns the directory of the path, with only minimal cleaning.
// Only redundant dots and slashes are removed, and only at the end.
func (p Path) Dir() Path {
	s := p.String()
	end := len(s)
	for end > 0 && s[end-1] != '/' {
		end--
	}
	for end > 1 && s[end-1] == '/' || end > 2 && hasPrefix(s[end-2:], "/.") {
		end--
	}
	if end == 0 {
		return "."
	}
	return NewPath(s[:end])
}

func (p Path) Base() string { return path.Base(string(p)) }

func (p Path) Split() (dir Path, base string) {
	strDir, strBase := path.Split(string(p))
	return Path(strDir), strBase
}

// Parts splits the path into its components.
// Multiple adjacent slashes are treated like a single slash.
// Parts that are single dots are skipped.
// Absolute paths have an empty string as its first part.
// All other parts are nonempty.
func (p Path) Parts() []string {
	if p.IsEmpty() {
		return nil
	}

	parts := strings.Split(string(p), "/")
	j := 0
	for i, part := range parts {
		if (i == 0 || part != "") && part != "." {
			parts[j] = part
			j++
		}
	}
	parts = parts[:j]
	if len(parts) == 0 {
		return []string{"."}
	}
	return parts
}

// Count returns the number of meaningful parts of the path.
// See Parts.
func (p Path) Count() int { return len(p.Parts()) }

func (p Path) HasPrefixText(prefix string) bool {
	return hasPrefix(string(p), prefix)
}

// HasPrefixPath returns whether the path starts with the given prefix.
// The basic unit of comparison is a path component, not a character.
func (p Path) HasPrefixPath(prefix Path) bool {
	// Handle the simple case first, without any memory allocations.
	if hasPrefix(string(p), string(prefix)) {
		return len(p) == len(prefix) || p[len(prefix)] == '/'
	}

	if prefix == "." {
		return !p.IsAbs()
	}

	si := 0
	pi := 0
	for {
		for si < len(p) && (p[si] == '.' || p[si] == '/') {
			si++
		}
		for pi < len(prefix) && (prefix[pi] == '.' || prefix[pi] == '/') {
			pi++
		}
		if si >= len(p) || pi >= len(prefix) {
			break
		}
		if p[si] != prefix[pi] {
			return false
		}
		si++
		pi++
	}

	parts := p.Parts()
	prefixParts := prefix.Parts()
	if len(prefixParts) > len(parts) {
		return false
	}
	for i, prefixPart := range prefixParts {
		if parts[i] != prefixPart {
			return false
		}
	}
	return true
}

func (p Path) ContainsText(contained string) bool {
	return contains(string(p), contained)
}

// ContainsPath returns whether the sub path is part of the path.
// The basic unit of comparison is a path component, not a character.
//
// Note that the paths used in pkglint may contain seemingly unnecessary
// components, like "../../wip/mk/../../devel/gettext-lib". To ignore these
// components, use ContainsPathCanonical instead.
func (p Path) ContainsPath(sub Path) bool {
	limit := len(p) - len(sub)
	for i := 0; i <= limit; i++ {
		if (i == 0 || p[i-1] == '/') && p[i:].HasPrefixPath(sub) {
			return true
		}
	}
	return sub == "."
}

func (p Path) HasSuffixText(suffix string) bool {
	return hasSuffix(string(p), suffix)
}

// HasSuffixPath returns whether the path ends with the given suffix.
// The basic unit of comparison is a path component, not a character.
func (p Path) HasSuffixPath(suffix Path) bool {
	return hasSuffix(string(p), string(suffix)) &&
		(len(p) == len(suffix) || p[len(p)-len(suffix)-1] == '/')
}

func (p Path) HasBase(base string) bool { return p.Base() == base }

func (p Path) TrimSuffix(suffix string) Path {
	return Path(strings.TrimSuffix(string(p), suffix))
}

func (p Path) Replace(from, to string) Path {
	return Path(strings.Replace(string(p), from, to, -1))
}

func (p Path) JoinClean(s RelPath) Path {
	return Path(path.Join(string(p), string(s)))
}

func (p Path) JoinNoClean(s RelPath) Path {
	return Path(string(p) + "/" + string(s))
}

func (p Path) Clean() Path { return NewPath(path.Clean(string(p))) }

// CleanDot returns the path with single dots removed and double slashes
// collapsed.
func (p Path) CleanDot() Path {
	if !p.ContainsText(".") && !p.ContainsText("//") {
		return p
	}

	parts := p.Parts()
	return NewPath(strings.Join(parts, "/"))
}

// Differs from path.Clean in that only "../../" is replaced, not "../".
// Also, the initial directory is always kept.
// This is to provide the package path as context in deeply nested .include chains.
func (p Path) CleanPath() Path {
	parts := p.Parts()

	for i := 2; i+3 < len(parts); /* nothing */ {
		if parts[i] != ".." && parts[i+1] != ".." && parts[i+2] == ".." && parts[i+3] == ".." {
			if i+4 == len(parts) || parts[i+4] != ".." {
				parts = append(parts[:i], parts[i+4:]...)
				continue
			}
		}
		i++
	}

	if len(parts) == 0 {
		return "."
	}
	return NewPath(strings.Join(parts, "/"))
}

func (p Path) IsAbs() bool {
	return len(p) > 0 && (p[0] == '/' || len(p) > 2 && p[1] == ':' && p[2] == '/')
}

// Rel returns the relative path from this path to the other.
//
// The returned path is a canonical relative path.
// It starts with a possibly empty sequence of "../",
// followed by a possibly empty sequence of non-dotdot directories.
// It may have a single dot at the end, which means the path goes to a directory.
func (p Path) Rel(other Path) RelPath {
	fp := filepath.FromSlash(p.String())
	fpOther := filepath.FromSlash(other.String())
	rel, err := filepath.Rel(fp, fpOther)
	assertNil(err, "Relpath from %q to %q", p, other)
	return NewRelPath(NewPath(filepath.ToSlash(rel)))
}

// CurrPath is a path that is either absolute or relative to the current
// working directory. It is used in command line arguments and for
// loading files from the file system, and later in the diagnostics.
type CurrPath string

func NewCurrPath(p Path) CurrPath { return CurrPath(p) }

func NewCurrPathString(p string) CurrPath { return CurrPath(p) }

func NewCurrPathSlash(p string) CurrPath {
	return CurrPath(filepath.ToSlash(p))
}

func (p CurrPath) GoString() string { return p.AsPath().GoString() }

func (p CurrPath) String() string { return string(p) }

func (p CurrPath) AsPath() Path { return Path(p) }

func (p CurrPath) IsEmpty() bool { return p.AsPath().IsEmpty() }

func (p CurrPath) Dir() CurrPath {
	return CurrPath(p.AsPath().Dir())
}

func (p CurrPath) Base() string { return p.AsPath().Base() }

func (p CurrPath) Split() (dir CurrPath, base string) {
	pathDir, pathBase := p.AsPath().Split()
	return NewCurrPath(pathDir), pathBase
}

func (p CurrPath) Parts() []string { return p.AsPath().Parts() }

func (p CurrPath) IsAbs() bool { return p.AsPath().IsAbs() }

func (p CurrPath) HasPrefixPath(prefix CurrPath) bool {
	return p.AsPath().HasPrefixPath(prefix.AsPath())
}

func (p CurrPath) ContainsPath(sub Path) bool {
	return p.AsPath().ContainsPath(sub)
}

func (p CurrPath) ContainsText(text string) bool {
	return p.AsPath().ContainsText(text)
}

func (p CurrPath) HasSuffixPath(suffix Path) bool {
	return p.AsPath().HasSuffixPath(suffix)
}

func (p CurrPath) HasSuffixText(suffix string) bool {
	return p.AsPath().HasSuffixText(suffix)
}

func (p CurrPath) HasBase(base string) bool {
	return p.AsPath().HasBase(base)
}

func (p CurrPath) TrimSuffix(suffix string) CurrPath {
	return NewCurrPath(p.AsPath().TrimSuffix(suffix))
}

func (p CurrPath) ReplaceSuffix(from string, to string) CurrPath {
	trimmed := p.TrimSuffix(from)
	assert(trimmed != p)
	return NewCurrPathString(trimmed.String() + to)
}

func (p CurrPath) Clean() CurrPath { return CurrPath(p.AsPath().Clean()) }

func (p CurrPath) CleanDot() CurrPath {
	return NewCurrPath(p.AsPath().CleanDot())
}

func (p CurrPath) CleanPath() CurrPath {
	return CurrPath(p.AsPath().CleanPath())
}

func (p CurrPath) JoinNoClean(other RelPath) CurrPath {
	return CurrPath(p.AsPath().JoinNoClean(other))
}

func (p CurrPath) JoinClean(other RelPath) CurrPath {
	return NewCurrPath(p.AsPath().JoinClean(other))
}

func (p CurrPath) Rel(rel CurrPath) RelPath {
	return p.AsPath().Rel(rel.AsPath())
}

func (p CurrPath) Rename(newName CurrPath) error {
	return os.Rename(string(p), string(newName))
}

func (p CurrPath) Lstat() (os.FileInfo, error) { return os.Lstat(string(p)) }

func (p CurrPath) Stat() (os.FileInfo, error) { return os.Stat(string(p)) }

func (p CurrPath) Exists() bool {
	_, err := p.Lstat()
	return err == nil
}

func (p CurrPath) IsFile() bool {
	info, err := p.Lstat()
	return err == nil && info.Mode().IsRegular()
}

func (p CurrPath) IsDir() bool {
	info, err := p.Lstat()
	return err == nil && info.IsDir()
}

func (p CurrPath) Chmod(mode os.FileMode) error {
	return os.Chmod(string(p), mode)
}

func (p CurrPath) ReadDir() ([]os.FileInfo, error) {
	return ioutil.ReadDir(string(p))
}

func (p CurrPath) ReadPaths() []CurrPath {
	infos, err := p.ReadDir()
	if err != nil {
		return nil
	}
	var filenames []CurrPath
	for _, info := range infos {
		if !isIgnoredFilename(info.Name()) {
			joined := p.JoinNoClean(NewRelPathString(info.Name())).CleanPath()
			filenames = append(filenames, joined)
		}
	}
	return filenames
}

func (p CurrPath) Open() (*os.File, error) { return os.Open(string(p)) }

func (p CurrPath) ReadString() (string, error) {
	bytes, err := ioutil.ReadFile(string(p))
	return string(bytes), err
}

func (p CurrPath) WriteString(s string) error {
	return ioutil.WriteFile(string(p), []byte(s), 0666)
}

// PkgsrcPath is a path relative to the pkgsrc root.
type PkgsrcPath string

func NewPkgsrcPath(p Path) PkgsrcPath {
	_ = NewRelPath(p)
	return PkgsrcPath(p)
}

func (p PkgsrcPath) String() string { return string(p) }

func (p PkgsrcPath) AsPath() Path { return NewPath(string(p)) }

func (p PkgsrcPath) AsRelPath() RelPath { return RelPath(p) }

func (p PkgsrcPath) Dir() PkgsrcPath {
	return NewPkgsrcPath(p.AsPath().Dir())
}

func (p PkgsrcPath) Base() string { return p.AsPath().Base() }

func (p PkgsrcPath) Count() int { return p.AsPath().Count() }

func (p PkgsrcPath) HasPrefixPath(prefix Path) bool {
	return p.AsPath().HasPrefixPath(prefix)
}

func (p PkgsrcPath) JoinNoClean(other RelPath) PkgsrcPath {
	return NewPkgsrcPath(p.AsPath().JoinNoClean(other))
}

// PackagePath is a path relative to the package directory. It is used
// for the PATCHDIR and PKGDIR variables, as well as dependencies and
// conflicts on other packages.
//
// It can have two forms:
//  - patches (further down)
//  - ../../category/package/* (up to the pkgsrc root, then down again)
type PackagePath string

func NewPackagePath(p RelPath) PackagePath {
	return PackagePath(p)
}

func NewPackagePathString(p string) PackagePath {
	return PackagePath(NewRelPathString(p))
}

func (p PackagePath) AsPath() Path { return Path(p) }

func (p PackagePath) AsRelPath() RelPath { return RelPath(p) }

func (p PackagePath) String() string { return p.AsPath().String() }

func (p PackagePath) JoinNoClean(other RelPath) PackagePath {
	return NewPackagePathString(p.AsPath().JoinNoClean(other).String())
}

func (p PackagePath) CleanPath() PackagePath {
	return NewPackagePathString(p.AsPath().CleanPath().String())
}

func (p PackagePath) IsEmpty() bool { return p.AsPath().IsEmpty() }

func (p PackagePath) HasPrefixPath(sub Path) bool {
	return p.AsPath().HasPrefixPath(sub)
}

func (p PackagePath) ContainsPath(sub Path) bool {
	return p.AsPath().ContainsPath(sub)
}

func (p PackagePath) ContainsText(contained string) bool {
	return p.AsPath().ContainsText(contained)
}

func (p PackagePath) Replace(from, to string) PackagePath {
	return NewPackagePathString(strings.Replace(string(p), from, to, -1))
}

// RelPath is a path that is relative to some base directory that is not
// further specified.
type RelPath string

func NewRelPath(p Path) RelPath {
	assert(!p.IsAbs())
	return RelPath(p)
}

func NewRelPathString(p string) RelPath {
	return NewRelPath(NewPath(p))
}

func (p RelPath) AsPath() Path { return NewPath(string(p)) }

func (p RelPath) String() string { return p.AsPath().String() }

func (p RelPath) IsEmpty() bool { return p.AsPath().IsEmpty() }

func (p RelPath) Split() (RelPath, string) {
	dir, base := p.AsPath().Split()
	return NewRelPath(dir), base
}

func (p RelPath) Dir() RelPath {
	return RelPath(p.AsPath().Dir())
}

func (p RelPath) Base() string { return p.AsPath().Base() }

func (p RelPath) HasBase(base string) bool { return p.AsPath().HasBase(base) }

func (p RelPath) Parts() []string { return p.AsPath().Parts() }

func (p RelPath) Count() int { return p.AsPath().Count() }

func (p RelPath) Clean() RelPath { return NewRelPath(p.AsPath().Clean()) }

func (p RelPath) CleanDot() RelPath {
	return NewRelPath(p.AsPath().CleanDot())
}

func (p RelPath) CleanPath() RelPath {
	return RelPath(p.AsPath().CleanPath())
}

func (p RelPath) JoinNoClean(other RelPath) RelPath {
	return RelPath(p.AsPath().JoinNoClean(other))
}

func (p RelPath) Replace(from string, to string) RelPath {
	return RelPath(p.AsPath().Replace(from, to))
}

func (p RelPath) HasPrefixPath(prefix Path) bool {
	return p.AsPath().HasPrefixPath(prefix)
}

func (p RelPath) HasPrefixText(prefix string) bool {
	return p.AsPath().HasPrefixText(prefix)
}

func (p RelPath) ContainsPath(sub Path) bool {
	return p.AsPath().ContainsPath(sub)
}

func (p RelPath) ContainsText(text string) bool {
	return p.AsPath().ContainsText(text)
}

func (p RelPath) HasSuffixPath(suffix Path) bool {
	return p.AsPath().HasSuffixPath(suffix)
}

func (p RelPath) HasSuffixText(suffix string) bool {
	return p.AsPath().HasSuffixText(suffix)
}

func (p RelPath) Rel(other Path) RelPath { return p.AsPath().Rel(other) }
