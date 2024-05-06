# $NetBSD: Makefile,v 1.114 2024/05/06 08:27:48 jperkin Exp $

DISTNAME=		cmus-2.10.0
PKGREVISION=		7
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=cmus/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://cmus.github.io/
COMMENT=		Small, fast and powerful text mode music player
LICENSE=		gnu-gpl-v2

EXTRACT_USING=		bsdtar
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_CC_FEATURES+=	c11

REPLACE_SH+=		cmus-status-display

CONFIGURE_ARGS+=	prefix=${PREFIX}
# not in pkgsrc yet
CONFIGURE_ARGS+=	CONFIG_ROAR=n
# requires systemd
CONFIGURE_ARGS+=	CONFIG_MPRIS=n
CONFIGURE_ARGS+=	mandir=${PREFIX}/${PKGMANDIR}
PLIST_VARS+=		coreaudio sunaudio oss

.include "../../mk/oss.buildlink3.mk"
.if ${OPSYS} != "NetBSD" && ${OSS_TYPE} != "none"
PLIST.oss=	yes
CONFIGURE_ARGS+=	CONFIG_OSS=y
.else
CONFIGURE_ARGS+=	CONFIG_OSS=n
.endif

.if ${OPSYS} == "SunOS" || exists(/usr/include/sys/audioio.h)
CONFIGURE_ARGS+=	CONFIG_SUN=y
PLIST.sunaudio=		yes
.else
CONFIGURE_ARGS+=	CONFIG_SUN=n
.endif

.if ${OPSYS} == "Darwin"
PLIST.coreaudio=	yes
.endif

.include "options.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
