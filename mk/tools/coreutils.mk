# $NetBSD: coreutils.mk,v 1.2 2005/04/26 15:32:05 jlam Exp $
#
# This Makefile fragment unconditionally replaces the system-supplied
# "core" utilities with the ones from the GNU coreutils package when
# "coreutils" is added to USE_TOOLS.
#
# Set TOOLS_DEPENDS.coreutils to "DEPENDS" to get a run-time dependency
# on coreutils.
#

.if !defined(TOOLS_IGNORE.coreutils) && !empty(USE_TOOLS:Mcoreutils)
.  if !empty(PKGPATH:Msysutils/coreutils)
MAKEFLAGS+=		TOOLS_IGNORE.coreutils=
.  else
TOOLS_DEPENDS.coreutils?=	BUILD_DEPENDS
${TOOLS_DEPENDS.coreutils}+=	coreutils>=5.2.1:../../sysutils/coreutils

# List of core utilities for which we'll create symlinks under
# ${TOOLS_DIR}.  This isn't every utility provided by coreutils, but
# is instead restricted to just the ones that are also listed in
# mk/platform/*.mk.
#
_TOOLS_COREUTILS+=	[ basename cat chgrp chmod chown cp cut date	\
			dirname echo env expr false head hostname id ln	\
			ls mkdir mv nice pwd rm rmdir sort tail tee	\
			test touch tr true tsort wc

# Create symlinks for each of the coreutils under ${TOOLS_DIR}.
.    for _t_ in ${_TOOLS_COREUTILS}
TOOLS_SYMLINK+=		${_t_}
TOOLS_REAL_CMD.${_t_}=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.    endfor
.    undef _t_
.  endif
.endif
