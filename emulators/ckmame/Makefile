# $NetBSD: Makefile,v 1.71 2023/01/20 11:42:40 wiz Exp $

DISTNAME=		ckmame-2.0
PKGREVISION=		3
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

GCC_REQD+=		9 # std::filesystem
USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099915
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.endif

.include "../../devel/cmake/build.mk"
.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_API_DEPENDS.libzip+=	libzip>=1.8
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
