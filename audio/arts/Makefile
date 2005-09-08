# $NetBSD: Makefile,v 1.47 2005/09/08 15:51:40 jdc Exp $

DISTNAME=	arts-1.4.2
CATEGORIES=	audio
HOMEPAGE=	http://www.kde.org/areas/multimedia/
COMMENT=	Analog Real-Time Synthesizer

# XXX: hack - work round an ICE with GCC 3.3 on sparc
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
GCC_REQD+=              3.4
.endif

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	kdelibs-2*

USE_TOOLS+=	perl pkg-config

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

_IN_ARTS_BUILD=		yes
.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
