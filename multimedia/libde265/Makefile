# $NetBSD: Makefile,v 1.13 2023/12/30 10:23:57 wiz Exp $

DISTNAME=	libde265-1.0.15
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libde265
COMMENT=	Open h.265 video codec implementation
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake autoreconf pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-sherlock265
CONFIGURE_ARGS+=	--enable-encoder
PKGCONFIG_OVERRIDE+=	libde265.pc.in

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
