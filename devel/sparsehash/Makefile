# $NetBSD: Makefile,v 1.11 2012/09/15 17:21:52 dholland Exp $
#

DISTNAME=		sparsehash-2.0.2
CATEGORIES=		devel
MASTER_SITES=		http://sparsehash.googlecode.com/files/

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		http://goog-sparsehash.sourceforge.net/
COMMENT=		Extremely memory-efficient hash_map implementation
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

TEST_TARGET=		check

INSTALL_MAKE_FLAGS=	docdir=${PREFIX}/share/doc/sparsehash

.include "../../mk/bsd.pkg.mk"
