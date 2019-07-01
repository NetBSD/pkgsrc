# $NetBSD: Makefile,v 1.40 2019/07/01 04:07:56 ryoon Exp $

DISTNAME=		moc-2.5.2
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://ftp.daper.net/pub/soft/moc/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter.schuller@infidyne.com
HOMEPAGE=		https://moc.daper.net/
COMMENT=		Curses based console audio player
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		eq
SUBST_STAGE.eq=		pre-configure
SUBST_FILES.eq=		configure
SUBST_SED.eq=		-e 's," == "," = ",g'
SUBST_MESSAGE.eq=	Fixing non-portable == in test

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	config.example.in options.c
SUBST_SED.oss=		-e s,/dev/dsp,${DEVOSSAUDIO},g
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.
.endif

.if ${OSS_TYPE} == "none"
CONFIGURE_ARGS+=	--without-oss
.endif

# not in pkgsrc?
CONFIGURE_ARGS+=	--without-rcc

# no buildlink?
CONFIGURE_ARGS+=	--without-timidity

# if you're one of the two people with music collections in musepack,
# want this, and can get it to work, please send a patch
CONFIGURE_ARGS+=	--without-musepack

BUILDLINK_TRANSFORM+=	l:db:db4

LDFLAGS.SunOS+=		-lsocket

# ${PREFIX}/bin/mocp contains path to pkg-config in work/.tools/.
# It is harmless.
CHECK_WRKREF_SKIP=	bin/mocp

.include "options.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
