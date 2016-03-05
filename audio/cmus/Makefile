# $NetBSD: Makefile,v 1.59 2016/03/05 11:28:03 jperkin Exp $

DISTNAME=		cmus-2.6.0
PKGREVISION=		6
CATEGORIES=		audio
MASTER_SITES=		-https://github.com/cmus/cmus/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		http://cmus.github.io/
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

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
