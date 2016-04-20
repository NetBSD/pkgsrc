# $NetBSD: Makefile,v 1.37 2016/04/20 12:10:34 nros Exp $
#

DISTNAME=		xmms-crossfade-0.2.9
PKGREVISION=		10
CATEGORIES=		audio
MASTER_SITES=		http://www.eisenlohr.org/xmms-crossfade/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eisenlohr.org/xmms-crossfade/
COMMENT=		Crossfading/Gapless Plugin for XMMS
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LDFLAGS+=		${LIBOSSAUDIO}
OSS_DEFS+=		-DDEFAULT_OSS_ALT_AUDIO_DEVICE='"${DEVOSSSOUND}"'
MAKE_ENV+=		OSS_DEFS=${OSS_DEFS:Q}

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-oss
.endif

.include "../../mk/bsd.pkg.mk"
