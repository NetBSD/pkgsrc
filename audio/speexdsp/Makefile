# $NetBSD: Makefile,v 1.6 2022/07/03 09:40:24 wiz Exp $

DISTNAME=	speexdsp-1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/speex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.speex.org/
COMMENT=	Open-source, patent-free voice codec DSP library
LICENSE=	modified-bsd

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	speexdsp.pc.in
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_CPU} == "aarch64"
CONFIGURE_ARGS+=	--disable-neon
.endif

BUILDLINK_API_DEPENDS.speex+=	speex>=1.2rc2
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
