# $NetBSD: Makefile,v 1.7 2004/12/28 23:18:18 reed Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
