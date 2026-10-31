# $NetBSD: Makefile,v 1.3 2026/10/31 21:45:52 hauke Exp $

DISTNAME=	bstring-${PKGVER}
PKGNAME=	libbstring-${PKGVER}
PKGVER=		1.1.1
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
