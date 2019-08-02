# $NetBSD: Makefile,v 1.24 2019/08/02 04:44:21 adam Exp $

DISTNAME=	zstd-1.4.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://facebook.github.io/zstd/
COMMENT=	Fast real-time compression algorithm
LICENSE=	modified-bsd OR gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		ggrep gmake pkg-config
PKGCONFIG_OVERRIDE+=	lib/libzstd.pc.in
MAKE_FLAGS=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}

BUILD_TARGET=		allmost
TEST_TARGET=		test

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
