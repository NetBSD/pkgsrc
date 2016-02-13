# $NetBSD: Makefile,v 1.13 2016/02/13 08:46:02 wiz Exp $

DISTNAME=	liborcus-0.9.2
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://kohei.us/files/orcus/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://gitlab.com/orcus/orcus
COMMENT=	Import filter library for spreadsheet documents
LICENSE=	mpl-2.0

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
