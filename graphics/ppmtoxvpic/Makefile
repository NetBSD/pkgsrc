# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:51 jlam Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
