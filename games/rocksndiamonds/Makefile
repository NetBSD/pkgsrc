# $NetBSD: Makefile,v 1.20 2004/12/03 15:14:57 wiz Exp $
#

.include "Makefile.common"

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	solaris
.else
BUILD_TARGET=	x11
.endif
CONFLICTS=	rocksndiamonds-sdl-[1-9]*
