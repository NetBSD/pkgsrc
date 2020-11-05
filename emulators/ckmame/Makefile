# $NetBSD: Makefile,v 1.56 2020/11/05 09:08:03 ryoon Exp $

DISTNAME=		ckmame-1.0
PKGREVISION=		10
CATEGORIES=		emulators
MASTER_SITES=		https://www.nih.at/ckmame/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.nih.at/ckmame/
COMMENT=		Check ROM sets for MAME
LICENSE=		modified-bsd

USE_TOOLS+=		pkg-config perl:test
USE_CMAKE=		yes
TEST_TARGET=		check

BUILDLINK_API_DEPENDS.libzip+=	libzip>=1.0

.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
