# $NetBSD: Makefile,v 1.39 2012/09/11 23:59:29 asau Exp $
#

DISTNAME=		cmus-v2.4.3
PKGNAME=		${DISTNAME:S/-v/-/}
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cmus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		http://cmus.sourceforge.net/
COMMENT=		Cmus is a small, fast and powerful text mode music player
LICENSE=		gnu-gpl-v2

CONFLICTS+=		cmus-unofficial-[0-9]*

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
