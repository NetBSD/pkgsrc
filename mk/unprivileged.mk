# $NetBSD: unprivileged.mk,v 1.3 2005/09/28 21:55:32 rillig Exp $
#
# Ease configuration of unprivileged (non-root) builds.
#
# UNPRIVILEGED		If set to 'yes', enable unprivileged builds.
#			Disabled by default.
#
# UNPRIVILEGED_GROUP	Specifies the group name (or gid) that will be used
#			to install files.  Guessed if empty.
#
# UNPRIVILEGED_USER	Specifies the user name (or uid) that will be used
#			to install files.  Guessed if empty.

.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])

# Guess which user/group has to be used.
.  if !defined(UNPRIVILEGED_USER) || empty(UNPRIVILEGED_USER)
UNPRIVILEGED_USER!=	${ID} -n -u
.  endif
.  if !defined(UNPRIVILEGED_GROUP) || empty(UNPRIVILEGED_GROUP)
UNPRIVILEGED_GROUP!=	${ID} -n -g
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

# Override installation modes.  As a regular user, we may have problems
# when overwriting files if they are not writable.
BINMODE=		755
NONBINMODE=		644

# mtree is useless as a regular user because it won't set directory
# ownerships correctly.
NO_MTREE=		yes

# As a regular user, creation of other users and groups won't work, so
# disable this step by default.
PKG_CREATE_USERGROUP=	NO

# Override commands that won't work as a regular user.
CHGRP=			${TRUE}
CHOWN=			${TRUE}
SU_CMD=			${SH} -c

# Do not attempt to modify /etc/shells as a regular user.
PKG_REGISTER_SHELLS=	NO

.endif
