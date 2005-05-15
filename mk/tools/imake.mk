# $NetBSD: imake.mk,v 1.8 2005/05/15 23:27:44 jlam Exp $
#
# This Makefile fragment handles packages that need imake and xmkmf
# to build X11-related packages.  The correct imake and xmkmf tools
# are placed under ${TOOLS_DIR}/bin, so that they may be invoked by
# their bare names.  The tools are chosen based on which type of X11
# distribution pkgsrc will be using, e.g. X11_TYPE.
#
# Variables defined by this file are:
#
#	IMAKE		path to imake tool + any imake-specific args
#	XMKMF_CMD	path to xmkmf tool + any xmkmf-specific args
#	XMKMF		command to create all Makefiles from Imakefiles,
#			usually "xmkmf -a".
#
# TOOLS_IMAKE, TOOLS_XMKMF_CMD and TOOLS_XMKMF are set to the same
# corresponding values.
#
# Optional variables that may be defined by the package are:
#
#	IMAKEOPTS	Options to pass to imake
#	XMKMF_FLAGS	Options to pass to xmkmf
#
# If they are non-empty, then a wrapper script will be created instead
# of a symlink for the corresponding tool.
#
# A platform/${OPSYS}.mk file may note that additional tools are
# required when using imake by setting _IMAKE_TOOLS to the appropriate
# value, e.g. _IMAKE_TOOLS+=gmake to use GNU make to build packages
# that use imake.
#
# This file is included by mk/tools/replace.mk and follows the same
# rules as for other replacement tools.
#

# Continue to allow USE_IMAKE until packages have been taught to use the
# new syntax.
#
.if defined(USE_IMAKE)
USE_TOOLS+=	imake
.endif

# Skip the processing at the end of replace.mk.  If we need to use
# imake, then we always want the clause below to trigger.
#
_TOOLS_USE_PKGSRC.imake=	yes

.if !defined(TOOLS_IGNORE.imake) && !empty(USE_TOOLS:Mimake)
.  if !empty(PKGPATH:Mx11/imake) || !empty(PKGPATH:Mx11/xorg-imake)
MAKEFLAGS+=			TOOLS_IGNORE.imake=
.  else
#
# Depending on which X11_TYPE we're using, depend on the correct package
# to pull in imake and xmkmf.
#
.    if defined(X11_TYPE) && (${X11_TYPE} == "XFree86")
TOOLS_DEPENDS.imake?=		imake>=4.4.0:../../x11/imake
TOOLS_REAL_CMD.imake?=		${X11PREFIX}/${X11ROOT_PREFIX}/bin/imake
TOOLS_REAL_CMD.xmkmf?=		${X11PREFIX}/${X11ROOT_PREFIX}/bin/xmkmf
.    elif defined(X11_TYPE) && (${X11_TYPE} == "xorg")
TOOLS_DEPENDS.imake?=		xorg-imake>=6.8:../../x11/xorg-imake
TOOLS_REAL_CMD.imake?=		${X11PREFIX}/${X11ROOT_PREFIX}/bin/imake
TOOLS_REAL_CMD.xmkmf?=		${X11PREFIX}/${X11ROOT_PREFIX}/bin/xmkmf
.    else # ${X11_TYPE} == "native"
TOOLS_REAL_CMD.imake?=		${X11BASE}/bin/imake
TOOLS_REAL_CMD.xmkmf?=		${X11BASE}/bin/xmkmf
.    endif
TOOLS_REAL_ARGS.imake?=		${IMAKEOPTS}
TOOLS_REAL_ARGS.xmkmf?=		${XMKMF_FLAGS}
#
# If we're using xpkgwedge, then we need to invoke the special xmkmf
# script that will find imake config files in both ${PREFIX} and in
# ${X11BASE}.
#
.    if !empty(USE_XPKGWEDGE:M[yY][eE][sS])
TOOLS_REAL_CMD.xmkmf=		${X11PREFIX}/bin/pkgxmkmf
.    endif
#
# Add any extra tools that may be required when using imake, e.g. gmake.
#
USE_TOOLS+=			${_IMAKE_TOOLS:Nimake}
#
# Define IMAKE and XMKMF_CMD and create wrappers/symlinks corresponding
# to imake and xmkmf.
#
TOOLS_CREATE+=			imake xmkmf
TOOLS_${_TOOLS_VARNAME.imake}=	${TOOLS_REAL_CMD.imake} ${TOOLS_REAL_ARGS.imake}
TOOLS_${_TOOLS_VARNAME.xmkmf}=	${TOOLS_REAL_CMD.xmkmf} ${TOOLS_REAL_ARGS.xmkmf}
TOOLS_XMKMF=			${${_TOOLS_VARNAME.xmkmf}} -a
${_TOOLS_VARNAME.imake}=	${TOOLS_${_TOOLS_VARNAME.imake}}
${_TOOLS_VARNAME.xmkmf}=	${TOOLS_${_TOOLS_VARNAME.xmkmf}}
XMKMF?=				${TOOLS_XMKMF}
.  endif
.endif
