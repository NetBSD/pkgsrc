# $NetBSD: unprivileged.mk,v 1.12 2007/07/04 20:54:48 jlam Exp $
#
# This file collects definitions that are useful when using pkgsrc as an
# unprivileged (non-root) user. It is included automatically by the
# pkgsrc infrastructure.
#
# The following variables may be set by the pkgsrc user in mk.conf:
#
# UNPRIVILEGED		: YesNo (default: undefined)
#	If set to 'yes', enable unprivileged builds.
#
# UNPRIVILEGED_GROUP	: Groupname (default: the current group)
#	Specifies the group name (or gid) that will be used to install
#	files.
#
# UNPRIVILEGED_USER	: Username (default: the current user)
#	Specifies the user name (or uid) that will be used to install
#	files.

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

# PKG_USERS_VARS is a list of variables that hold bare user names, e.g
#	APACHE_USER, etc.
#
# PKG_GROUPS_VARS is a list of variables that hold bare group names, e.g
#	UUCP_GROUP, etc.
#
PKG_USERS_VARS?=	# empty
PKG_GROUPS_VARS?=	# empty
BUILD_DEFS+=		${PKG_USERS_VARS} ${PKG_GROUPS_VARS}

# Override per-package, custom users and groups.
.    for _var_ in ${PKG_USERS_VARS}
${_var_}=		${UNPRIVILEGED_USER}
.    endfor
.    for _var_ in ${PKG_GROUPS_VARS}
${_var_}=		${UNPRIVILEGED_GROUP}
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
