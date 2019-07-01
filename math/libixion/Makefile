# $NetBSD: Makefile,v 1.13 2019/07/01 04:08:31 ryoon Exp $

DISTNAME=	libixion-0.14.1
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://kohei.us/files/ixion/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/ixion/ixion
COMMENT=	General purpose formula parser & interpreter
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	libixion.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
