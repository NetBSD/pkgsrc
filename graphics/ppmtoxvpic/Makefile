# $NetBSD: Makefile,v 1.5 2003/07/17 21:42:25 grant Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
