# $NetBSD: Makefile,v 1.2 2002/03/13 17:37:16 fredb Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
