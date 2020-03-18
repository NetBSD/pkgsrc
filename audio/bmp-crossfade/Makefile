# $NetBSD: Makefile,v 1.22 2020/03/18 17:42:17 joerg Exp $

PKGNAME=		bmp-crossfade-0.3.11
DISTNAME=		xmms-crossfade-0.3.11
PKGREVISION=		14
CATEGORIES=		audio
MASTER_SITES=		https://www.eisenlohr.org/xmms-crossfade/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.eisenlohr.org/xmms-crossfade/
COMMENT=		Crossfading/Gapless Plugin for BMP

LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

LDFLAGS+=		${LIBOSSAUDIO}
OSS_DEFS+=		-DDEFAULT_OSS_ALT_AUDIO_DEVICE='"${DEVOSSSOUND}"'
MAKE_ENV+=		OSS_DEFS=${OSS_DEFS:Q}

CHECK_PORTABILITY_SKIP+=	configure.in

.include "../../audio/bmp/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

CONFIGURE_ARGS+=		--enable-player=bmp
GNU_CONFIGURE_LIBSUBDIR=	bmp/Output

.if ${OSS_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-oss
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
