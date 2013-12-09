# $NetBSD: Makefile,v 1.5 2013/12/09 15:00:39 wiz Exp $

DISTNAME=	liborcus-0.5.1
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://kohei.us/files/orcus/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://gitorious.org/orcus/
COMMENT=	Import filter library for spreadsheet documents
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=			gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-boost-system=boost_system
CONFIGURE_ARGS+=	--disable-spreadsheet-model
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ENV+=		ZLIB_CFLAGS="-I${BUILDLINK_PREFIX.zlib}/include"
CONFIGURE_ENV+=		ZLIB_LIBS="${LINKER_RPATH_FLAG}${BUILDLINK_PREFIX.zlib}/lib -L${BUILDLINK_PREFIX.zlib}/lib -lz"

PKGCONFIG_OVERRIDE+=	liborcus.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
