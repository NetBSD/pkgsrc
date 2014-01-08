# $NetBSD: Makefile,v 1.1 2014/01/08 23:07:09 wiz Exp $

DISTNAME=	libbdplus-0.1.0
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/libbdplus/0.1.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/libbdplus.html
COMMENT=	Research project to implement the BD+ System Specifications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libbdplus.pc.in

.include "../../multimedia/libaacs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
