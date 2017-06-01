Package Tasks
=============

*pkgtasks* is a shell script library to ease writing POSIX-compliant shell
scripts to handle common tasks during installation or removal of a package,
e.g.,

  * creating groups and users needed by the package

  * creating and removing directories with special permissions and
    ownership,

  * copying example config files to their final locations during package
    installation, and removing them during package removal if they don't
    differ from the example ones,

  * reminding the user of files that may be customized after package
    installation.

Package tasks have the property of *idempotence* -- they may be invoked
multiple times, but the result must be the same as when invoked once, e.g.,
the `shells` task adds an entry to /etc/shells, but will avoid adding the
same entry more than once.


Getting sources
---------------

The latest version of *pkgtasks* is 1.9 and was released on May 31st, 2017.

See the [release notes](NEWS.md) for information about the changes in this
and all previous releases.


Documentation
-------------

A script may load task modules to define shell functions to perform
various tasks.  A task module is loaded in a POSIX-compliant shell script
by adding the following boilerplate to the script:

	# Import the task loader.
	: ${TASK_MODULE_DIR:=/usr/pkg/share/pkgtasks-1}
	. "${TASK_MODULE_DIR}/load.subr"

	# Load task modules.
	task_load preinstall

The individual package tasks supported by *pkgtasks* are:

  * `directories`: create and remove directories outside of package tree
  * `files`: copy and remove configuration files
  * `fonts`: regenerate X11 font indices
  * `groups`: create groups and warn about groups that may be removed
  * `info_files`: register and unregister GNU info files
  * `ocaml_findlib`: update OCaml findlib search paths
  * `permissions`: check and set modes and permissions on special files
  * `shells`: register and unregister login shells
  * `shlibs`: update the shared library cache
  * `users`: create users and warn about users that may be removed

These package tasks support `${PKG_DESTDIR}` to manipulate the correct
filesystem paths for a destdir-installed package.

For convenience, these have been composed into larger meta-tasks:

  * `preinstall`: tasks performed before files are installed
  * `preremove`: tasks performed before files are removed
  * `postinstall`: tasks performed after files are installed
  * `postremove`: tasks performed after files are removed

There are also several utility tasks that may be used to write portable
scripts:

  * `cleanup`: run functions upon improper exit
  * `compare`: compare two files for equality
  * `createfile`: create empty files
  * `dirwalk`: walk a directory tree using depth-first traversal
  * `echo`: write to standard output through a buffer
  * `lock`: create or release a lock file
  * `makedir`: make a directory hierarchy
  * `maketemp`: make unique, temporary files
  * `match`: match lines with a fnmatch(3) glob pattern
  * `platform`: determine the platform (operating system)
  * `quote`: quote strings for use with shell eval
  * `random`: generate random numbers (badly)
  * `refcount`: reference-count system resources
  * `say`: write to standard output with a tag
  * `sort`: sort lines from standard input
  * `taskfunc`: generic function hook for meta-tasks
  * `tee`: duplicate writes to standard output into files
  * `truthy`: evaluate truthiness
  * `valid_options`: check validity of option strings
  * `version`: compare version strings
  * `which`: locate a program file in the $PATH

The documentation for each of these tasks is in man-page style in the
header comments for each task module.
