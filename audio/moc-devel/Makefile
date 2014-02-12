# $NetBSD: Makefile,v 1.17 2014/02/12 23:17:34 tron Exp $

DISTNAME=		moc-2.5.0-beta1
PKGREVISION=		2
PKGNAME=		${DISTNAME:S/-beta/b/:moc%=moc-devel%}
CATEGORIES=		audio
MASTER_SITES=		http://ftp.daper.net/pub/soft/moc/unstable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter.schuller@infidyne.com
HOMEPAGE=		http://moc.daper.net/
COMMENT=		Curses based console audio player
LICENSE=		gnu-gpl-v2

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

LIBS.SunOS+=    -lsocket

BUILDLINK_TRANSFORM+=	l:db:db4

# ${PREFIX}/bin/mocp contains path to pkg-config in work/.tools/.
# It is harmless.
CHECK_WRKREF_SKIP=	bin/mocp

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
