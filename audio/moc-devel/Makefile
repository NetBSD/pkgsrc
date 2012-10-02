# $NetBSD: Makefile,v 1.9 2012/10/02 23:47:58 asau Exp $

DISTNAME=		moc-2.5.0-alpha3
PKGNAME=		${DISTNAME:S/-alpha/./:moc%=moc-devel%}
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.daper.net/pub/soft/moc/unstable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter.schuller@infidyne.com
HOMEPAGE=		http://moc.daper.net/
COMMENT=		Curses based console audio player

CONFLICTS=		moc-[0-9]*

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
#USE_TOOLS+=		autoconf automake

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	config.example options.c
SUBST_SED.oss=		-e s,/dev/dsp,${DEVOSSAUDIO},g
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

.include "options.mk"
###
### This target is [currently] for regenerating configure to add the 
### sched_get_priority_max check of librt.
###
#pre-configure:
#	cd ${WRKSRC} && autoreconf -v -i
post-extract:
	${CP} ${FILESDIR}/getline.c ${WRKSRC}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=   rm:-Wl,--export-dynamic
.endif

LIBS.SunOS+=    -lsocket

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
