# $NetBSD: Makefile,v 1.78 2019/07/02 06:15:29 nia Exp $

DISTNAME=		cmus-2.8.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=cmus/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		https://cmus.github.io/
COMMENT=		Small, fast and powerful text mode music player
LICENSE=		gnu-gpl-v2

EXTRACT_USING=		bsdtar
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

REPLACE_SH+=		cmus-status-display

# C11 atomics
GCC_REQD+=		4.9

CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	CONFIG_ALSA=n
# not in pkgsrc yet
CONFIGURE_ARGS+=	CONFIG_ROAR=n
# requires systemd
CONFIGURE_ARGS+=	CONFIG_MPRIS=n
CONFIGURE_ARGS+=	mandir=${PREFIX}/${PKGMANDIR}
PLIST_VARS+=		coreaudio sunaudio oss

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
PLIST.oss=	yes
CONFIGURE_ARGS+=	CONFIG_OSS=y
.else
CONFIGURE_ARGS+=	CONFIG_OSS=n
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" || exists(/usr/include/sys/audioio.h)
CONFIGURE_ARGS+=	CONFIG_SUN=y
PLIST.sunaudio=		yes
.else
CONFIGURE_ARGS+=	CONFIG_SUN=n
.endif

.if ${OPSYS} == "Darwin"
PLIST.coreaudio=	yes
.endif

NOT_PAX_MPROTECT_SAFE+=	bin/cmus

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
