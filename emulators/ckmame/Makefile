# $NetBSD: Makefile,v 1.76 2023/10/24 22:09:03 wiz Exp $

DISTNAME=		ckmame-2.0
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		https://www.nih.at/ckmame/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.nih.at/ckmame/
COMMENT=		Check ROM sets for MAME
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config perl:test
TEST_TARGET=		test

USE_CXX_FEATURES+=	c++17 filesystem

.include "../../devel/cmake/build.mk"
.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_API_DEPENDS.libzip+=	libzip>=1.8
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
