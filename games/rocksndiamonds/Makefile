# $NetBSD: Makefile,v 1.17 2003/12/17 21:30:39 heinz Exp $
#

.include "Makefile.common"

COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)

.if ${OPSYS} == "SunOS"
ALL_TARGET=	solaris
.elif ${OPSYS} == "Darwin"
ALL_TARGET=	mac
.else
ALL_TARGET=	x11
.endif
CONFLICTS=	rocksndiamonds-sdl-[1-9]*
