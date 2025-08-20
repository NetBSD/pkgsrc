# $NetBSD: Makefile,v 1.6 2025/08/20 11:34:46 wiz Exp $

DISTNAME=	soxr-0.1.3-Source
PKGNAME=	lib${DISTNAME:S/-Source//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soxr/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/p/soxr/wiki/Home/
COMMENT=	SoX Resample library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=NO
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_PLATFORM:MDarwin-*-aarch64*}
CMAKE_CONFIGURE_ARGS+=	-DWITH_CR32S=NO
.endif

PKGCONFIG_OVERRIDE+=	src/soxr.pc.in
PKGCONFIG_OVERRIDE+=	src/soxr-lsr.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
