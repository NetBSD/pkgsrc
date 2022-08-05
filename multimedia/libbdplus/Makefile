# $NetBSD: Makefile,v 1.3 2022/08/05 08:02:20 adam Exp $

DISTNAME=	libbdplus-0.2.0
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libbdplus/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/libbdplus.html
COMMENT=	Research project to implement the BD+ System Specifications
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimizations
PKGCONFIG_OVERRIDE+=	src/libbdplus.pc.in

.include "../../multimedia/libaacs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
