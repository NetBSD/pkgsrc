# $NetBSD: Makefile,v 1.2 2021/12/08 16:02:29 adam Exp $

DISTNAME=	libslirp-4.3.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://elmarco.fedorapeople.org/
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
