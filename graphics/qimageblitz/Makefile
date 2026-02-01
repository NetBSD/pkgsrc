# $NetBSD: Makefile,v 1.43 2026/02/01 09:04:12 wiz Exp $

DISTNAME=	qimageblitz-0.0.6
PKGREVISION=	30
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=qimageblitz/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/qimageblitz/
COMMENT=	Interm graphical effect and filter library for KDE4.0

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

#BUILD_MAKE_FLAGS+=	VERBOSE=1

PKGCONFIG_OVERRIDE+=	blitz/qimageblitz.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
