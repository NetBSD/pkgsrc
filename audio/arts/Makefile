# $NetBSD: Makefile,v 1.19 2003/08/01 05:58:20 grant Exp $

DISTNAME=	arts-1.1.3
CATEGORIES=	audio
COMMENT=	Analog Real-Time Synthesizer

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	kdelibs-2*

USE_BUILDLINK2=		yes
USE_PERL5=		build

LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool ${WRKSRC}/libltdl/libtool
CONFIGURE_ENV+=		ac_cv_path_PKG_CONFIG=no

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
