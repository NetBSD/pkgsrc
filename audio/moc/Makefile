# $NetBSD: Makefile,v 1.28 2016/03/05 11:28:04 jperkin Exp $

DISTNAME=		moc-2.5.0
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://ftp.daper.net/pub/soft/moc/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter.schuller@infidyne.com
HOMEPAGE=		http://moc.daper.net/
COMMENT=		Curses based console audio player
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
# XXX: Only needed to regen configure script
#USE_TOOLS+=		autoconf automake

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	config.example options.c
SUBST_SED.oss=		-e s,/dev/dsp,${DEVOSSAUDIO},g
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

BUILDLINK_TRANSFORM+=	l:db:db4

LDFLAGS.SunOS+=		-lsocket

# ${PREFIX}/bin/mocp contains path to pkg-config in work/.tools/.
# It is harmless.
CHECK_WRKREF_SKIP=	bin/mocp

# XXX: This target is [currently] for regenerating configure to add the
# XXX: sched_get_priority_max check of librt.
#pre-configure:
#	cd ${WRKSRC} && autoreconf -v -i

.include "options.mk"

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
