# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:58 jlam Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
