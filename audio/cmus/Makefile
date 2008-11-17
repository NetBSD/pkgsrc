# $NetBSD: Makefile,v 1.14 2008/11/17 13:30:34 ahoka Exp $
#

DISTNAME=		cmus-2.2.0
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://mirror.greaterscope.net/cmus/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ahoka@NetBSD.org
HOMEPAGE=		http://cmus.sourceforge.net/
COMMENT=		Cmus is an ncurses based music player with a lot of features

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	CONFIG_ALSA=n
CONFIGURE_ARGS+=	mandir=${PREFIX}/${PKGMANDIR}/
PLIST_VARS+=		sunaudio oss

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
PLIST.oss=	yes
CONFIGURE_ARGS+=        CONFIG_OSS=y
.else
CONFIGURE_ARGS+=        CONFIG_OSS=n
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" || exists(/usr/include/sys/audioio.h)
CONFIGURE_ARGS+=	CONFIG_SUN=y
PLIST.sunaudio=		yes
.else
CONFIGURE_ARGS+=        CONFIG_SUN=n
.endif

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
