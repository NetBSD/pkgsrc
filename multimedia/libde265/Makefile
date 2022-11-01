# $NetBSD: Makefile,v 1.6 2022/11/01 20:41:51 adam Exp $

DISTNAME=	libde265-1.0.9
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libde265
COMMENT=	Open h.265 video codec implementation
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-sherlock265
PKGCONFIG_OVERRIDE+=	libde265.pc.in

.include "../../mk/bsd.pkg.mk"
