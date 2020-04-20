# $NetBSD: Makefile,v 1.1 2020/04/20 17:34:14 nia Exp $

DISTNAME=	libopusenc-0.2.1
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	High-level API for encoding .opus files
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libopusenc.pc.in

.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
