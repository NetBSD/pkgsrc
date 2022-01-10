# $NetBSD: Makefile,v 1.4 2022/01/10 01:46:29 ryoon Exp $

DISTNAME=	libcutl-1.10.0
PKGREVISION=	3
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

CONFIGURE_ARGS+=	--with-external-boost
CONFIGURE_ARGS+=	--with-external-expat

PKGCONFIG_OVERRIDE+=	libcutl.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
