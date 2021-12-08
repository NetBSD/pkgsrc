# $NetBSD: Makefile,v 1.63 2021/12/08 16:04:14 adam Exp $

DISTNAME=		ckmame-1.1
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		https://www.nih.at/ckmame/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.nih.at/ckmame/
COMMENT=		Check ROM sets for MAME
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config perl:test
USE_CMAKE=		yes
TEST_TARGET=		check

GCC_REQD+=	8 # std::filesystem

.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_API_DEPENDS.libzip+=	libzip>=1.8
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
