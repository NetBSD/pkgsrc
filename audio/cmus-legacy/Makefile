# $NetBSD: Makefile,v 1.3 2024/05/06 08:40:21 jperkin Exp $

DISTNAME=		cmus-2.7.1
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=cmus/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://cmus.github.io/
COMMENT=		Small and fast text mode music player (C99 version)
LICENSE=		gnu-gpl-v2

EXTRACT_USING=		bsdtar
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

REPLACE_SH+=		cmus-status-display

CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	mandir=${PREFIX}/${PKGMANDIR}

CONFIGURE_ARGS+=	CONFIG_FLAC=y
CONFIGURE_ARGS+=	CONFIG_VORBIS=y

# heavy C++ dependency unsuitable for old platforms
CONFIGURE_ARGS+=	CONFIG_CUE=n
# not in pkgsrc yet
CONFIGURE_ARGS+=	CONFIG_ROAR=n
# requires systemd
CONFIGURE_ARGS+=	CONFIG_MPRIS=n

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OPSYS} != "NetBSD" && ${OSS_TYPE} != "none"
PLIST.oss=		yes
CONFIGURE_ARGS+=	CONFIG_OSS=y
.else
CONFIGURE_ARGS+=	CONFIG_OSS=n
.endif

PLIST_VARS+=		sunaudio
.if ${OPSYS} == "SunOS" || exists(/usr/include/sys/audioio.h)
CONFIGURE_ARGS+=	CONFIG_SUN=y
PLIST.sunaudio=		yes
.else
CONFIGURE_ARGS+=	CONFIG_SUN=n
.endif

PLIST_VARS+=		libao
.if ${OSS_TYPE} == "none"
.  include "../../audio/libao/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_AO=y
PLIST.libao=		yes
.endif

.include "options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
