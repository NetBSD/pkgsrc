# $NetBSD: Makefile,v 1.4 2003/07/13 13:52:14 wiz Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
