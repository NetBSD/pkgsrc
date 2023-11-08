# $NetBSD: Makefile,v 1.77 2023/11/08 13:19:05 wiz Exp $

DISTNAME=		ckmame-2.0
PKGREVISION=		6
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
