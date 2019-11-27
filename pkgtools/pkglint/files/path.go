package pkglint

import (
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
	"strings"
)

// Path is a slash-separated path in the filesystem.
// It may be absolute or relative.
// Some paths may contain placeholders like @VAR@ or ${VAR}.
// The base directory of relative paths depends on the context
// in which the path is used.
//
// TODO: Consider adding several more specialized types of path:
// TODO: CurrPath, relative to the current working directory
// TODO: PkgsrcPath, relative to the pkgsrc root
// TODO: PackagePath, relative to the package directory
// TODO: RelativePath, relative to some other basedir
type Path string

func NewPath(name string) Path { return Path(name) }

func NewPathSlash(name string) Path { return Path(filepath.ToSlash(name)) }

func (p Path) String() string { return string(p) }

func (p Path) GoString() string { return sprintf("%q", string(p)) }

func (p Path) Dir() Path { return Path(path.Dir(string(p))) }

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
	if p == "" {
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

// TODO: Check each call whether ContainsPath is more appropriate; add tests
func (p Path) ContainsText(contained string) bool {
	return contains(string(p), contained)
}

// ContainsPath returns whether the sub path is part of the path.
// The basic unit of comparison is a path component, not a character.
//
// Note that the paths used in pkglint may contains seemingly unnecessary
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

func (p Path) ContainsPathCanonical(sub Path) bool {
	cleaned := cleanpath(p)
	return cleaned.ContainsPath(sub)
}

func (p Path) HasSuffixText(suffix string) bool {
	return hasSuffix(string(p), suffix)
}

// HasSuffixPath returns whether the path ends with the given prefix.
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

func (p Path) JoinClean(s Path) Path {
	return Path(path.Join(string(p), string(s)))
}

func (p Path) JoinNoClean(s Path) Path {
	return Path(string(p) + "/" + string(s))
}

func (p Path) Clean() Path { return NewPath(path.Clean(string(p))) }

// CleanDot returns the path with single dots removed and double slashes
// collapsed.
func (p Path) CleanDot() Path {
	if !p.ContainsText(".") {
		return p
	}

	var parts []string
	for i, part := range p.Parts() {
		if !(part == "." || i > 0 && part == "") { // See Parts
			parts = append(parts, part)
		}
	}
	if len(parts) == 0 {
		return "."
	}
	return NewPath(strings.Join(parts, "/"))
}

func (p Path) IsAbs() bool {
	return p.HasPrefixText("/") || filepath.IsAbs(filepath.FromSlash(string(p)))
}

// Rel returns the relative path from this path to the other.
func (p Path) Rel(other Path) Path {
	fp := filepath.FromSlash(p.String())
	fpOther := filepath.FromSlash(other.String())
	rel, err := filepath.Rel(fp, fpOther)
	assertNil(err, "Relpath from %q to %q", p, other)
	return NewPath(filepath.ToSlash(rel))
}

func (p Path) Rename(newName Path) error {
	return os.Rename(string(p), string(newName))
}

func (p Path) Lstat() (os.FileInfo, error) { return os.Lstat(string(p)) }

func (p Path) Stat() (os.FileInfo, error) { return os.Stat(string(p)) }

func (p Path) Exists() bool {
	_, err := p.Lstat()
	return err == nil
}

func (p Path) IsFile() bool {
	info, err := p.Lstat()
	return err == nil && info.Mode().IsRegular()
}

func (p Path) IsDir() bool {
	info, err := p.Lstat()
	return err == nil && info.IsDir()
}

func (p Path) Chmod(mode os.FileMode) error {
	return os.Chmod(string(p), mode)
}

func (p Path) ReadDir() ([]os.FileInfo, error) {
	return ioutil.ReadDir(string(p))
}

func (p Path) Open() (*os.File, error) { return os.Open(string(p)) }

func (p Path) ReadString() (string, error) {
	bytes, err := ioutil.ReadFile(string(p))
	return string(bytes), err
}

func (p Path) WriteString(s string) error {
	return ioutil.WriteFile(string(p), []byte(s), 0666)
}
