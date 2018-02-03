# $NetBSD: Makefile,v 1.33 2018/02/03 12:04:03 jdolecek Exp $

DISTNAME=		libzip-1.4.0
CATEGORIES=		archivers devel
MASTER_SITES=		https://libzip.org/download/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.libzip.org/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

USE_CMAKE=		yes
USE_TOOLS+=		perl:build

TEST_TARGET=		test
# for tests
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# avoid running regression tests with not yet installed libs,
# the above LD_LIBRARY_PATH is not passed to commands executed
# via cmake and zip lib is not found when invoking ziptool
BUILD_TARGET=   zip
INSTALL_TARGET= install/fast
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
