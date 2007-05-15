# $NetBSD: Makefile,v 1.36 2007/05/15 19:39:12 heinz Exp $

DISTNAME=	zlib-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		http://www.gzip.org/zlib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zlib.net/
COMMENT=	General purpose data compression library

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

MAKE_ENV+=	PKGSRC_LDFLAGS=${LDFLAGS:Q}

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
