# $NetBSD: Makefile,v 1.5 2022/07/25 11:12:26 wiz Exp $

DISTNAME=	libde265-1.0.8
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_PROJECT=	libde265
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libde265/
COMMENT=	Open h.265 video codec implementation
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libde265.pc.in

CONFIGURE_ARGS+=	--disable-sherlock265

.include "../../mk/bsd.pkg.mk"
