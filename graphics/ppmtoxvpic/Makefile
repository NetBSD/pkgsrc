# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:28 wiz Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
