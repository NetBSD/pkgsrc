# $NetBSD: Makefile,v 1.21 2004/12/22 16:46:19 reed Exp $
#

.include "Makefile.common"

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)
PKGREVISION=	1

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	solaris
.else
BUILD_TARGET=	x11
.endif
CONFLICTS=	rocksndiamonds-sdl-[1-9]*
