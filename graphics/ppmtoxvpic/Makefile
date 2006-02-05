# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:38 joerg Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
