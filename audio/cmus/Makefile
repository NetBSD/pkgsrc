# $NetBSD: Makefile,v 1.2 2006/07/10 00:56:25 minskim Exp $
#

DISTNAME=		cmus-2.0.3
CATEGORIES=		audio
MASTER_SITES=		http://onion.dynserv.net/~timo/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	 	webmaster@deepblack24.de
HOMEPAGE=		http://onion.dynserv.net/~timo/files/
COMMENT=	 	Cmus is an ncurses based mp3/ogg player with a lot of features

HAS_CONFIGURE=		yes
USE_TOOLS=		gmake

CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	CONFIG_ALSA=n
CONFIGURE_ARGS+=	CONFIG_ARTS=n
CONFIGURE_ARGS+=	CONFIG_OSS=y
CONFIGURE_ARGS+=	CONFIG_MAD=y
CONFIGURE_ARGS+=	CONFIG_AO=y
CONFIGURE_ARGS+=	CONFIG_FLAC=y
CONFIGURE_ARGS+=	mandir=${PREFIX}/man/

.if exists(/usr/include/sys/audioio.h)
PLIST_SUBST+=	SUN=""
.else
PLIST_SUBST+=	SUN="@comment "
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	CONFIG_SUN=y
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
