# $NetBSD: Makefile,v 1.22 2005/01/16 19:33:27 kristerw Exp $
#

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)
PKGREVISION=	1

.include "Makefile.common"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	solaris
.else
BUILD_TARGET=	x11
.endif
CONFLICTS=	rocksndiamonds-sdl-[1-9]*
