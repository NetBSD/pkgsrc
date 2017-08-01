# $NetBSD: Makefile,v 1.69 2017/08/01 14:58:52 wiz Exp $

DISTNAME=		cmus-2.7.1
PKGREVISION=		6
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=cmus/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		https://cmus.github.io/
COMMENT=		Cmus is a small, fast and powerful text mode music player
LICENSE=		gnu-gpl-v2

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

REPLACE_SH+=		cmus-status-display

CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	CONFIG_ALSA=n
CONFIGURE_ARGS+=	mandir=${PREFIX}/${PKGMANDIR}/
PLIST_VARS+=		sunaudio oss

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

NOT_PAX_MPROTECT_SAFE+=	bin/cmus

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
