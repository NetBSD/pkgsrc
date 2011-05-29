# $NetBSD: Makefile,v 1.8 2011/05/29 15:12:26 cheusov Exp $
#

DISTNAME=		sparsehash-1.10
CATEGORIES=		devel
MASTER_SITES=		http://google-sparsehash.googlecode.com/files/

MAINTAINER=		vle@gmx.net
HOMEPAGE=		http://goog-sparsehash.sourceforge.net/
COMMENT=		Several hash-map implementations in use at Google
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS=	docdir=${PREFIX}/share/doc/sparsehash

.include "../../mk/bsd.pkg.mk"
