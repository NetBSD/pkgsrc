# $NetBSD: Makefile,v 1.11 2008/05/10 14:56:33 obache Exp $
#

DISTNAME=		cmus-2.2.0
CATEGORIES=		audio
MASTER_SITES=		http://mirror.greaterscope.net/cmus/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		webmaster@deepblack24.de
HOMEPAGE=		http://cmus.sourceforge.net/
COMMENT=		Cmus is an ncurses based mp3/ogg player with a lot of features

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	CONFIG_ALSA=n
CONFIGURE_ARGS+=	CONFIG_OSS=y
CONFIGURE_ARGS+=	mandir=${PREFIX}/${PKGMANDIR}/
PLIST_VARS=		sunaudio

.if exists(/usr/include/sys/audioio.h)
PLIST.sunaudio=		yes
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	CONFIG_SUN=y
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
