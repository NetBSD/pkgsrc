# $NetBSD: Makefile,v 1.49 2020/06/13 10:46:55 wiz Exp $

DISTNAME=		libzip-1.7.1
CATEGORIES=		archivers devel
MASTER_SITES=		https://libzip.org/download/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.libzip.org/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

USE_CMAKE=		yes
USE_TOOLS+=		perl:build

TEST_TARGET=		test
# for tests
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/lib

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
