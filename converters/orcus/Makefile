# $NetBSD: Makefile,v 1.6 2013/12/11 07:52:25 wiz Exp $

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

PKGCONFIG_OVERRIDE+=	liborcus.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
