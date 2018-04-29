# $NetBSD: Makefile,v 1.9 2018/04/29 21:31:52 adam Exp $

DISTNAME=	libixion-0.13.0
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

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	libixion.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds1.2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
