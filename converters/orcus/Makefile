# $NetBSD: Makefile,v 1.2 2013/11/20 13:23:42 obache Exp $

PKGNAME=	orcus-${PKGVERSION}
DISTNAME=	liborcus-${PKGVERSION}
PKGVERSION=	0.5.1
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://kohei.us/files/orcus/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://kohei.us/files/orcus/src/
COMMENT=	Import filter library for spreadsheet documents
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake gmake pkg-config
USE_LANGUAGES=	c c++
CONFIGURE_ARGS+=	--with-boost-libdir=${PREFIX}/lib \
	--with-boost-system=boost_system \
	--disable-spreadsheet-model --disable-werror
CONFIGURE_ENV+=	ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-L/usr/lib -lz"

PKGCONFIG_OVERRIDE+=	liborcus.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
