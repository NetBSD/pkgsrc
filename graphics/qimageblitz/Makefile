# $NetBSD: Makefile,v 1.36 2023/10/24 22:09:30 wiz Exp $

DISTNAME=	qimageblitz-0.0.6
PKGREVISION=	27
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=qimageblitz/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/qimageblitz
COMMENT=	Interm graphical effect and filter library for KDE4.0

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

#BUILD_MAKE_FLAGS+=	VERBOSE=1

PKGCONFIG_OVERRIDE+=	blitz/qimageblitz.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
