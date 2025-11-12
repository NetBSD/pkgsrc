# $NetBSD: Makefile,v 1.3 2025/11/12 20:22:25 mrg Exp $

DISTNAME=	libopusenc-0.2.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	High-level API for encoding .opus files
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-doc

PKGCONFIG_OVERRIDE+=	libopusenc.pc.in

.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
