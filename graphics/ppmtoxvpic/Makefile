# $NetBSD: Makefile,v 1.8 2005/02/21 20:26:11 hubertf Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
