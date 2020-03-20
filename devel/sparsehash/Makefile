# $NetBSD: Makefile,v 1.15 2020/03/20 11:57:33 nia Exp $
#


DISTNAME=		sparsehash-2.0.3
GITHUB_TAG=		${DISTNAME}
MASTER_SITES=		${MASTER_SITE_GITHUB:=sparsehash/}
CATEGORIES=		devel

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://goog-sparsehash.sourceforge.net/
COMMENT=		Extremely memory-efficient hash_map implementation
LICENSE=		modified-bsd

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

TEST_TARGET=		check

INSTALL_MAKE_FLAGS=	docdir=${PREFIX}/share/doc/sparsehash

.include "../../mk/bsd.pkg.mk"
