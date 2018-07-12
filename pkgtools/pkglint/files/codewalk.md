# The pkglint tour

> Note: I wish there were a tool for nicely rendering the below codewalk blocks.
> If you know of such a tool, please tell me.
> `godoc` codewalks don't count since [they are only supported for the Go distribution 
> itself](https://github.com/golang/go/issues/14369).
>
> See also:
>
> * [github/markup/#172](https://github.com/github/markup/issues/172#issuecomment-33241601) (closed)
> * [MarkdownHelper](https://github.com/BurdetteLamar/MarkdownHelper)

## The entry points

### Running pkglint

```codewalk
file   pkglint.go
start  ^func main
end    ^\}
```

When running pkglint, the `G` variable is set up first.
It contains the whole global state of pkglint.
(Except for some of the subpackages, which have to be initialized separately.)
All the interesting code is in the `Pkglint` type.
Having only a single global variable makes it easy to reset the global state during testing.

### Testing pkglint

Very similar code is used to set up the test and tear it down again:

```codewalk
file   check_test.go
start  ^func .* SetUpTest
end    ^\}
```

```codewalk
file   check_test.go
start  ^func .* TearDownTest
end    ^\}
```

## First contact: checking a single DESCR file

To learn how pkglint works internally, it is a good idea to start with
a very simple example.
Since the `DESCR` files have a very simple structure (they only contain
text for human consumption), they are the ideal target.
Let's trace an invocation of the command `pkglint DESCR` down to where
the actual checks happen.

```codewalk
file   pkglint.go
start  func main
```

```codewalk
file   pkglint.go
start  ^[\t]if exitcode
end    ^\t\}$
```

Since there are no command line options starting with a hyphen, we can
skip the command line parsing for this example.

```codewalk
file   pkglint.go
start  ^[\t]for _, arg
end    ^\}
```

The argument `DESCR` is saved in the `TODO` list, and then the pkgsrc
infrastructure data is loaded by `Initialize`.
This must happen in this order because pkglint needs to determine the
pkgsrc root directory, just in case there are two or more pkgsrc trees
in the local system.
The path of the pkgsrc directory is determined from the first command
line argument, which in this file is `DESCR`. From there, the pkgsrc
root is usually reachable via `../../`, and this is what pkglint tries.

After initializing the pkgsrc metadata,
all items from the TODO list are worked off and handed over to `CheckDirent`,
one after another.

```codewalk
file   pkglint.go
start  func CheckDirent
```

Since `DESCR` is a regular file, the next method to call is `Checkfile`.

```codewalk
file   pkglint.go
start  func Checkfile
```

```codewalk
file   pkglint.go
start  /basename, "DESCR"/
end    ^$
```

When compared to the code blocks around this one, it looks strange that
this one uses `hasPrefix` and the others use a direct string comparison.
But indeed, there are a few packages that actually have `DESCR.common`
files. So everything's fine here.

At this point, the file is loaded and converted to lines.
For DESCR files, this is very simple, so there's no need to dive into that.
The actual checks usually work on `Line` objects instead of files
because the lines offer nice methods for logging the diagnostics
and for automatically fixing the text (in pkglint's `--autofix` mode).

```codewalk
file   pkglint.go
start  func ChecklinesDescr
end    ^\}
```

Now we are where the actual action takes place.
The code looks straight-forward here.
First, each line is checked on its own,
and the final check is for too long files.
Pkglint takes great care to output all diagnostics in a logical order,
that is file by file, and top to bottom within each file.
Therefore the checks for individual lines happen before the other check.

The call to `SaveAutofixChanges` at the end looks a bit strange
since none of the visible checks fixes anything.
The autofix feature must be hidden in one of the line checks,
and indeed, the code for `CheckLineTrailingWhitespace` says:

```codewalk
file   linechecker.go
start  ^func CheckLineTrailingWhitespace
end    ^\}
```

This code is a typical example for using the autofix feature.
Some more details are described at the `Autofix` type itself
and at its typical call site `Line.Autofix()`:

```codewalk
file   linechecker.go
start  /^type Autofix/ upwhile /^\/\//
end    /^type Autofix/
```

```codewalk
file   line.go
start  /^func .* Autofix/ upwhile /^\/\//
end    /^func .* Autofix/
```

The journey ends here, and it hasn't been that difficult.
If that was too easy, have a look at the complex cases here:

```codewalk
file   mkline.go
start  /^func .* VariableNeedsQuoting
```

## Basic ingredients

Pkglint checks packages, and a package consists of several different files.
All pkgsrc files are text files, which are organized in lines.
Most pkglint diagnostics refer to a specific line,
therefore the `Line` type is responsible for producing the diagnostics.

### Line

Most checks in pkgsrc only need to look at a single line.
Lines that are independent of the file type are implemented in the `Line` type.
This type contains the methods `Errorf`, `Warnf` and `Notef` to produce diagnostics
of the following form:

```text
WARN: Makefile:3: COMMENT should not start with "A" or "An".
```

The definition for the `Line` type is:

```codewalk
file   line.go
start  ^type Line =
```

```codewalk
file   line.go
start  ^type LineImpl struct
end    ^\}
```

### MkLine

Most of the pkgsrc infrastructure is written in Makefiles. 
In these, there may be line continuations  (the ones ending in backslash).
Plus, they may contain Make variables of the form `${VARNAME}` or `${VARNAME:Modifiers}`,
and these are handled specially.

```codewalk
file   mkline.go
start  ^type MkLine =
```

```codewalk
file   mkline.go
start  ^type MkLineImpl struct
end    ^\}
```

### ShellLine

The instructions for building and installing packages are written in shell commands,
which are embedded in Makefile fragments.
The `ShellLine` type provides methods for checking shell commands and their individual parts.

```codewalk
file   shell.go
start  ^type ShellLine struct
end    ^\}
```
