# $NetBSD: Makefile,v 1.14 2010/01/24 13:26:11 wiz Exp $
#

PKGNAME=	ppmtoxvpic-0.99.9
PKGREVISION=	8
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert PPM image to preview pic readable by xv and gimp

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/xvpicmaker ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/ppmtoxvpic ${DESTDIR}${PREFIX}/bin

.include "../../x11/dfm/Makefile.common"
