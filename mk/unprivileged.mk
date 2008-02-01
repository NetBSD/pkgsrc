# $NetBSD: unprivileged.mk,v 1.15 2008/02/01 08:54:53 rillig Exp $
#
# This file collects definitions that are useful when using pkgsrc as an
# unprivileged (non-root) user. It is included automatically by the
# pkgsrc infrastructure.
#
# === User-settable variables ===
#
# UNPRIVILEGED
#	Whether to build packages as unprivileged user.
#
#	Default: (undefined)
#	Possible: yes no
#
# UNPRIVILEGED_USER
#	The user name (or numeric uid) that will be used to install
#	files.
#
#	Default: The user building the package
#
# UNPRIVILEGED_GROUP
#	The group name (or numeric gid) that will be used to install
#	files.
#
#	Default: The primary group of the user building the package
#
# UNPRIVILEGED_GROUPS
#       The group names that can be used to install files.  Where a
#       per-package custom group is declared that matches a group name
#       in this variable, it will be left unmodified.  Any per-package
#       custom group not in this list will be forced to the value of
#       UNPRIVILEGED_GROUP.
#
#       Default: The complete group membership of the user building
#       the package
#
# === Package-settable variables ===
#
# PKG_USERS_VARS
#	A list of variables that hold bare user names, e.g APACHE_USER, etc.
#
# PKG_GROUPS_VARS
#	A list of variables that hold bare group names, e.g UUCP_GROUP, etc.
#
# XXX: How can the user say that some of the packages shouldn't override
# the user and group names?
#
# PRIVILEGED_STAGES
#	A list of phases (not stages) that are run as the privileged
#	user. Some packages, when installed with just-in-time-su, leave
#	temporary files in the working directory, so the "clean" phase
#	must have enough priviledges to clean them up.
#
#	Possible: clean
#	Default: (undefined)
#
# === System-defined variables ===
#
# REAL_ROOT_USER
#	The name of an omnipotent user account on the system.
#
#	XXX: Why do we have this variable when it is set to ${ROOT_USER}
#	anyway for unprivileged builds? Shouldn't packages that require
#	such a user just fail in unprivileged mode?
#	(See NOT_FOR_UNPRIVILEGED.)
#
# REAL_ROOT_GROUP
#	The primary group of the REAL_ROOT_USER.
#
# ROOT_USER
#	XXX: ???
#
# ROOT_GROUP
#	The primary group of the ROOT_USER.
#
# BINOWN, BINGRP, GAMEOWN, GAMEGRP, MANOWN, MANGRP, SHAREOWN, SHAREGRP,
# DOCOWN, DOCGRP, BINMODE, NONBINMODE
#	Ownership and permissions of the various types of files that are
#	installed by the packages.
#
#	XXX: What do we need all these different variables for? Wouldn't
#	it be ok to install all files as ROOT_USER:ROOT_GROUP?
#
# PKG_CREATE_USERGROUP
#	Since an unprivileged user normally cannot create other users
#	and groups, this pkgsrc feature is disabled.
#
#	XXX: This setting should be moved into pkg_add.
#
# PKG_REGISTER_SHELLS
#	Since an unprivileged user normally cannot add entries to
#	/etc/shells, this pkgsrc feature is disabled.
#
#	XXX: See PKG_CREATE_USERGROUP
#
# TOOLS_PLATFORM.chown, TOOLS_PLATFORM.chgrp
#	These tools cannot be used in their full extent by unprivileged
#	users.
#
#	XXX: chgrp may work for some groups.
#
# Keywords: unprivileged root override
#

_VARGROUPS+=			unprivileged
_USER_VARS.unprivileged= \
	UNPRIVILEGED UNPRIVILEGED_GROUP UNPRIVILEGED_GROUPS UNPRIVILEGED_USER
_PKG_VARS.unprivileged=	\
	PKG_USER_VARS PKG_GROUP_VARS
_SYS_VARS.unprivileged= \
	REAL_ROOT_USER REAL_ROOT_GROUP ROOT_USER ROOT_GROUP \
	BINOWN BINGRP GAMEOWN GAMEGRP MANOWN MANGRP SHAREOWN SHAREGRP DOCOWN DOCGRP \
	BINMODE NONBINMODE \
	PKG_CREATE_USERGROUP PKG_REGISTER_SHELLS \
	TOOLS_PLATFORM.chgrp TOOLS_PLATFORM.chown SU_CMD

_UNPRIVILEGED=		# empty
.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
_UNPRIVILEGED+=		unprivileged
.endif
.if (${_USE_DESTDIR} == "user-destdir")
_UNPRIVILEGED+=		user-destdir
.endif

.if !empty(_UNPRIVILEGED)

# Guess which user/group has to be used.
.  if !defined(UNPRIVILEGED_USER) || empty(UNPRIVILEGED_USER)
UNPRIVILEGED_USER!=	${ID} -n -u
.  endif
.  if !defined(UNPRIVILEGED_GROUP) || empty(UNPRIVILEGED_GROUP)
UNPRIVILEGED_GROUP!=	${ID} -n -g
.  endif
.  if !defined(UNPRIVILEGED_GROUPS) || empty(UNPRIVILEGED_GROUPS)
UNPRIVILEGED_GROUPS!=	${ID} -n -G
.  endif

.  if empty(_UNPRIVILEGED:Munprivileged) && !empty(_UNPRIVILEGED:Muser-destdir)
# Only do following for privileged, user-destdir builds.
_SU_ROOT_USER:=		${ROOT_USER}
REAL_ROOT_USER:=	${ROOT_USER}
REAL_ROOT_GROUP:=	${ROOT_GROUP}
.  endif

# Override super-user account.
ROOT_GROUP=		${UNPRIVILEGED_GROUP}
ROOT_USER=		${UNPRIVILEGED_USER}

# Override user/group pairs used to install files.
BINGRP=			${UNPRIVILEGED_GROUP}
BINOWN=			${UNPRIVILEGED_USER}
GAMEGRP=		${UNPRIVILEGED_GROUP}
GAMEOWN=		${UNPRIVILEGED_USER}
MANGRP=			${UNPRIVILEGED_GROUP}
MANOWN=			${UNPRIVILEGED_USER}
SHAREGRP=		${UNPRIVILEGED_GROUP}
SHAREOWN=		${UNPRIVILEGED_USER}
DOCGRP=			${UNPRIVILEGED_GROUP}
DOCOWN=			${UNPRIVILEGED_USER}

# Override installation modes.  As a regular user, we may have problems
# when overwriting files if they are not writable.
BINMODE=		755
NONBINMODE=		644

.  if !empty(_UNPRIVILEGED:Munprivileged) && empty(_UNPRIVILEGED:Muser-destdir)
# Only do the following for unprivileged, normal builds.

PKG_USERS_VARS?=	# empty
PKG_GROUPS_VARS?=	# empty
BUILD_DEFS+=		${PKG_USERS_VARS} ${PKG_GROUPS_VARS}

# Override per-package custom users and groups, except for groups listed
# in UNPRIVILEGED_GROUPS.
.    for _var_ in ${PKG_USERS_VARS}
${_var_}=		${UNPRIVILEGED_USER}
.    endfor
.    for _var_ in ${PKG_GROUPS_VARS}
.      if empty(UNPRIVILEGED_GROUPS:M${${_var_}})
${_var_}=		${UNPRIVILEGED_GROUP}
.      endif
.    endfor
.  endif

.endif

.if !empty(_UNPRIVILEGED:Munprivileged)
# As a regular user, creation of other users and groups won't work, so
# disable this step by default.
PKG_CREATE_USERGROUP=	NO

# Override commands that won't work as a regular user.
TOOLS_PLATFORM.chgrp=	${TRUE} chgrp
TOOLS_PLATFORM.chown=	${TRUE} chown
SU_CMD=			${SH} -c

# Do not attempt to modify /etc/shells as a regular user.
PKG_REGISTER_SHELLS=	NO
.endif
