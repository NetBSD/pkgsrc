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

func (p Path) Parts() []string {
	return strings.FieldsFunc(string(p), func(r rune) bool { return r == '/' })
}

func (p Path) Count() int { return len(p.Parts()) }

func (p Path) HasPrefixText(prefix string) bool {
	return hasPrefix(string(p), prefix)
}

// HasPrefixPath returns whether the path starts with the given prefix.
// The basic unit of comparison is a path component, not a character.
func (p Path) HasPrefixPath(prefix Path) bool {
	return hasPrefix(string(p), string(prefix)) &&
		(len(p) == len(prefix) || p[len(prefix)] == '/')
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

// TODO: Check each call whether HasSuffixPath is more appropriate; add tests
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

func (p Path) IsAbs() bool {
	return p.HasPrefixText("/") || filepath.IsAbs(filepath.FromSlash(string(p)))
}

func (p Path) Rel(other Path) Path {
	fp := filepath.FromSlash(p.String())
	fpOther := filepath.FromSlash(other.String())
	rel, err := filepath.Rel(fp, fpOther)
	assertNil(err, "relpath from %q to %q", p, other)
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
