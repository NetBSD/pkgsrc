# $NetBSD: Makefile,v 1.3 2022/04/25 06:27:10 nia Exp $

DISTNAME=	libslirp-4.6.1
CATEGORIES=	net
MASTER_SITES=	https://gitlab.freedesktop.org/slirp/libslirp/uploads/83b199ea6fcdfc0c243dfde8546ee4c9/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/slirp/libslirp
COMMENT=	User-mode networking library
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/slirp.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
