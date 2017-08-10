Package Tasks
=============


Changes in version 1.13
-----------------------
**Released on 2017-08-08.**

* Make the output messages for the `groups` and `users` tasks easier
  to understand by making them slightly more verobse and changing
  the formatting.


Changes in version 1.12
-----------------------
**Released on 2017-08-06.**

* Use `${GTK_UPDATE_ICON_CACHE}` as the default command to update
  the GTK+ icon theme caches in the `icon_themes` task,
  defaulting to `true` if it is not set in the environment.  Also
  force an update of the icon caches from the `postremove`
  meta-task in case the icon theme is a composite of several
  packages.  This makes the behavior more compatible with **pkgsrc**.

* Bug fixes.


Changes in version 1.11
-----------------------
**Released on 2017-07-31.**

* Invoke `install-info` in a different way that matches how it is
  typically invoked in GNU projects.

* Add `icon_themes` task to update GTK+ icon theme caches.

* Bug fixes.


Changes in version 1.10
-----------------------
**Released on 2017-06-03.**

* Modify `Makefile.am` to always use the same pathname to refer to a
  built object.  This fixes the dependency graph in the case where
  `make` is invoked to run with multiple jobs.

* Change the output of the `directories` and `files` tasks to be
  less verbose in the most common case where a directory is
  created or a file is copied and permissions are immediately set
  on the directory or file.


Changes in version 1.9
----------------------
**Released on 2017-05-31.**

* Adapt `directories` and `files` tasks to unconditionally set
  permissions when new objects are created, and to not throw
  errors if the object is missing because it wasn't created in
  an earlier step.  This makes the behavior more compatible with
  **pkgsrc**.

* Depending on the values of certain environment variables, certain
  *add* or *remove* actions may not actually perform operations that
  change the system and still return successfully.  Always run the
  "check" actions for the corresponding main action so that any
  warning messages intended for the user are written to standard
  output.

* Make the `shlibs` task output more descriptive.


Changes in version 1.8
----------------------
**Released on 2017-05-29.**

* Change the output of the actions taken by each task, by being
  slightly more brief, and also accepting an environment variable
  `${TASK_MSG}` as the prefix string for each line of output.

* Bug fixes.


Changes in version 1.7
----------------------
**Released on 2017-05-29.**

* Back out two changes to make **pkgtasks** more compatible with
  what **pkgsrc** needs:

  - Don't use `OCAML_FINDLIB_REGISTER` environment variable since
    it is a package-settable variable in **pkgsrc**, not a user-
    settable one.

  - Don't use `PKG_CONFIG_PERMS` environment variable in the
    `permissions` task, which matches its usage in **pkgrsc**


Changes in version 1.6
----------------------
**Released on 2017-05-27.**

* Adjust `fonts` task to run `mkfontdir` on TTF and Type1 font
  directories automatically.

* Rename control variable `PKG_RCD_SCRIPTS` to `PKG_INIT_SCRIPTS`.
  This generalizes the variable name to allow for other init
  systems.

* Check `${PKG_CONFIG_PERMS}` in the `permissions` task.

* Make the `shlibs` task accept `LDCONFIG_ADD_CMD` and
  `LDCONFIG_REMOVE_CMD` as separate command lines to update the
  shared library cache depending on whether the task is called to
  *add* or *remove*.  The default action is still to invoke a bare
  `${LDCONFIG}` command.

* Adjust the `shlibs` task to accept standard input and to only
  update the cache if there are lines of the correct format.

* Fix `preinstall` meta-task to fail properly if groups and/or
  users don't exist.

* Add `platform` task to write the name of the platform or
  operating system to standard output.

* Automatically load the platform-specific module with the correct
  `platform_groupadd` and `platform_useradd` functions.

* Bug fixes and cleanup.


Changes in version 1.5
----------------------
**Released on 2017-05-17.**

* Support `~[string]` (tilde string) in a version string to sort
  before a release version, e.g., 1.2~rc1 sorts before 1.2.

* When invoking a meta-task, only be verbose when invoking tasks
  that typically affect system files and directories.  This
  makes the output a bit more friendly for the typicaly user,
  who is no longer bombarded with every trivial GNU info file
  registration.

* Bug fixes.


Changes in version 1.4
----------------------
**Released on 2017-05-14.**

* Allow duplicate logging of task output to a file through the
  `echo` task.

* Added `tee` task to duplicate standard input to standard output
  and into additional files.


Changes in version 1.3
----------------------
**Released on 2017-05-13.**

* Generalized refcount API so the refcount-file implementation
  may be deprecated in the future.

* Added option to suppress duplicate lines to the `sort` task.

* Added `valid_options` task to simplify checking for valid flags.

* Added `function` task as a generic hook for user-written tasks
  into the `preinstall`, `postinstall`, `preremove`, and
  `postremove` meta-tasks.

* Bug fixes.


Changes in version 1.2
----------------------
**Released on 2017-05-07.**

* Be more consistent with using `maketemp` to generate internal
  temporary files and directories.

* Added the `sort` task to sort lines from standard input.

* Sort input when performing `add` action of `directories` task,
  and reverse sort when performing `remove` action.  This causes
  path components to be created and removed in the correct order.


Changes in version 1.1
----------------------

**Released on 2017-05-05**

* Added the `which` task to locate a program in the search path.

* Changed the `fonts` task to search for indexing commands in the
  search path before falling back to defaults.  This makes the
  task more resilient to differences in how the X11 directories
  are laid out across different systems.

* Be more consistent with preserving standard error from commands
  used to perform tasks so that errors are visible for logging and
  debugging purposes.


Changes in version 1.0
----------------------

**Released on 2017-05-03**

* Initial release of pkgtasks-1-1.0.
