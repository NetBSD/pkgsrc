# $NetBSD: Makefile,v 1.18 2004/03/06 20:08:20 heinz Exp $
#

.include "Makefile.common"

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)

.if ${OPSYS} == "SunOS"
ALL_TARGET=	solaris
.else
ALL_TARGET=	x11
.endif
CONFLICTS=	rocksndiamonds-sdl-[1-9]*
# MacOS X/Darwin always needs sdl, so use rocksndiamonds-sdl
NOT_FOR_PLATFORM=	Darwin-*-*
