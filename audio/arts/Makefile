# $NetBSD: Makefile,v 1.86 2013/03/15 12:16:59 obache Exp $

DISTNAME=	arts-1.5.10
PKGREVISION=	11
CATEGORIES=	audio
HOMEPAGE=	http://multimedia.kde.org/
COMMENT=	Analog Real-Time Synthesizer

.include "../../meta-pkgs/kde3/Makefile.kde3"

REPLACE_SH+=	artsc/artsc-config.in artsc/artsdsp.in

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.if !empty(MACHINE_PLATFORM:MSunOS-5.1[0-9]-*) && \
    !empty(CC_VERSION:Mgcc-4.[6-9].*)
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -std=c99
.else
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=500
.endif

CONFLICTS+=	kdelibs-2*

USE_TOOLS+=	perl pkg-config

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "options.mk"

CONFIGURE_ARGS+=	--enable-libsuffix=none

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

post-patch:
	cd ${FILESDIR} && cp gslglib.* ${WRKSRC}/flow/gsl/

.include "../../mk/bsd.pkg.mk"
