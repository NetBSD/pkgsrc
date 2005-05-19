# $NetBSD: imake.mk,v 1.10 2005/05/19 05:27:25 jlam Exp $
#
# This Makefile fragment defines additional variables that are used
# by packages that need imake and xmkmf.
#
# Variables defined by this file are:
#
#	XMKMF, TOOLS_XMKMF
#		command to create all Makefiles from Imakefiles,
#		usually "xmkmf -a".
#
# Optional variables that may be defined by the package are:
#
#	IMAKEOPTS	Options to pass to imake
#	XMKMF_FLAGS	Options to pass to xmkmf
#
# A platform/${OPSYS}.mk file may note that additional tools are
# required when using imake by setting _IMAKE_TOOLS to the appropriate
# value, e.g. _IMAKE_TOOLS+=gmake to use GNU make to build packages
# that use imake.
#
# This file needs to be included before replace.mk as it modifies the
# PKGSRC_USE_TOOLS and USE_TOOLS variables that are used by replace.mk.
#

.if defined(USE_IMAKE)
USE_TOOLS+=	imake xmkmf
.endif

# imake and xmkmf imply each other
.if !empty(PKGSRC_USE_TOOLS:Mimake) || !empty(PKGSRC_USE_TOOLS:Mxmkmf)
PKGSRC_USE_TOOLS+=	imake xmkmf
.endif
.if !empty(USE_TOOLS:Mimake) || !empty(USE_TOOLS:Mxmkmf)
USE_TOOLS+=		imake xmkmf
.endif

# Add any extra tools that may be required when using imake, e.g. gmake.
USE_TOOLS+=		${_IMAKE_TOOLS:Nimake}

TOOLS_REAL_ARGS.imake?=	${IMAKEOPTS}
TOOLS_REAL_ARGS.xmkmf?=	${XMKMF_FLAGS}

TOOLS_XMKMF=		${${_TOOLS_VARNAME.xmkmf}} -a
XMKMF=			${${_TOOLS_VARNAME.xmkmf}} -a
