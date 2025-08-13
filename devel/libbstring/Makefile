# $NetBSD: Makefile,v 1.2 2025/08/13 08:56:12 hauke Exp $

DISTNAME=	bstring-${PKGVER}
PKGNAME=	libbstring-${PKGVER}
PKGVER=		1.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msteinert/bstring/releases/download/v${PKGVER}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/msteinert/bstring/
COMMENT=	String data type superior to the C library char buffer
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE+=	bstring.pc.in

INSTALLATION_DIRS=	include lib lib/pkgconfig

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
