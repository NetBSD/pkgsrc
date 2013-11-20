# $NetBSD: Makefile,v 1.3 2013/11/20 20:04:36 adam Exp $

DISTNAME=	liborcus-0.5.1
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://kohei.us/files/orcus/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://kohei.us/files/orcus/src/
COMMENT=	Import filter library for spreadsheet documents
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-boost-system=boost_system
CONFIGURE_ARGS+=	--disable-spreadsheet-model
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ENV+=		ZLIB_CFLAGS="-I/usr/include" ZLIB_LIBS="-L/usr/lib -lz"

PKGCONFIG_OVERRIDE+=	liborcus.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
