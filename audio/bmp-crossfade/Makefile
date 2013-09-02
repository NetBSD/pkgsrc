# $NetBSD: Makefile,v 1.5 2013/09/02 19:50:52 adam Exp $
#

PKGNAME=		bmp-crossfade-0.3.11
DISTNAME=		xmms-crossfade-0.3.11
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.eisenlohr.org/xmms-crossfade/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eisenlohr.org/xmms-crossfade/
COMMENT=		Crossfading/Gapless Plugin for BMP

LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

LDFLAGS+=		${LIBOSSAUDIO}
OSS_DEFS+=		-DDEFAULT_OSS_ALT_AUDIO_DEVICE='"${DEVOSSSOUND}"'
MAKE_ENV+=		OSS_DEFS=${OSS_DEFS:Q}

.include "../../audio/bmp/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

CONFIGURE_ARGS+=	--enable-player=bmp
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/bmp/Output

.if ${OSS_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-oss
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
