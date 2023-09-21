# $NetBSD: Makefile,v 1.7 2023/09/21 11:31:19 nros Exp $

DISTNAME=	libcutl-1.10.0
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://www.codesynthesis.com/download/libcutl/1.10/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.codesynthesis.com/projects/libcutl/
COMMENT=	C++ utility library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
FORCE_CXX_STD=	c++11

CONFIGURE_ARGS+=	--with-external-boost
CONFIGURE_ARGS+=	--with-external-expat

PKGCONFIG_OVERRIDE+=	libcutl.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
