# $NetBSD: Makefile,v 1.24 2004/02/06 13:48:05 tron Exp $

DISTNAME=	arts-1.2.0
PKGREVISION=	1
CATEGORIES=	audio
COMMENT=	Analog Real-Time Synthesizer

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	kdelibs-2*

USE_BUILDLINK2=		yes
USE_PERL5=		build

LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool ${WRKSRC}/libltdl/libtool
BUILD_DEPENDS+=		pkgconfig>=0.15.0:../../devel/pkgconfig

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../audio/esound/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
