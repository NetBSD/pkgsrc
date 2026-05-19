# $NetBSD: Makefile,v 1.17 2026/05/19 14:17:41 adam Exp $

DISTNAME=	sparsehash-2.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sparsehash/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://goog-sparsehash.sourceforge.net/
COMMENT=	Extremely memory-efficient hash_map implementation
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
TEST_TARGET=		check

INSTALL_MAKE_FLAGS=	docdir=${PREFIX}/share/doc/sparsehash

.include "../../mk/bsd.pkg.mk"
