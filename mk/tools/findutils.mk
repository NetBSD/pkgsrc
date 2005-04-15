# $NetBSD: findutils.mk,v 1.1 2005/04/15 07:33:43 jlam Exp $
#
# This Makefile fragment unconditionally replaces the system-supplied
# "find" utilities with the ones from the GNU findutils package when
# "findutils" is added to USE_TOOLS.
#
# Set TOOLS_DEPENDS.findutils to "DEPENDS" to get a run-time dependency
# on findutils.
#

.if !defined(TOOLS_IGNORE.findutils) && !empty(USE_TOOLS:Mfindutils)
.  if !empty(PKGPATH:Msysutils/findutils)
MAKEFLAGS+=		TOOLS_IGNORE.findutils=
.  else
TOOLS_DEPENDS.findutils?=	BUILD_DEPENDS
${TOOLS_DEPENDS.findutils}+=	findutils>=4.1:../../sysutils/findutils

# List of find utilities for which we'll create symlinks under  
# ${TOOLS_DIR}.
#
_TOOLS_FINDUTILS+=	find xargs

# Create symlinks for each of the findutils under ${TOOLS_DIR}.
.    for _t_ in ${_TOOLS_FINDUTILS}
TOOLS_SYMLINK+=		${_t_}
TOOLS_CMD.${_t_}=	${TOOLS_DIR}/bin/${_t_}
TOOLS_REAL_CMD.${_t_}=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}${_t_}
.    endfor
.    undef _t_
.  endif
.endif
