# $NetBSD: unprivileged.mk,v 1.10 2007/04/19 16:52:03 joerg Exp $
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

.if (defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])) || ${_USE_DESTDIR} == "user-destdir"

# Guess which user/group has to be used.
.  if !defined(UNPRIVILEGED_USER) || empty(UNPRIVILEGED_USER)
UNPRIVILEGED_USER!=	${ID} -n -u
.  endif
.  if !defined(UNPRIVILEGED_GROUP) || empty(UNPRIVILEGED_GROUP)
UNPRIVILEGED_GROUP!=	${ID} -n -g
.  endif

.if ${_USE_DESTDIR} == "user-destdir" && (!defined(UNPRIVILEGED) || empty(UNPRIVILEGED:M[Yy][Ee][Ss]))
_SU_ROOT_USER:=		${ROOT_USER}
REAL_ROOT_USER:=	${ROOT_USER}
REAL_ROOT_GROUP:=	${ROOT_GROUP}
.endif

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
.endif

.if (defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss]))
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
