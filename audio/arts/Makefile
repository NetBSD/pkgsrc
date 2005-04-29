# $NetBSD: Makefile,v 1.40 2005/04/29 13:49:02 reed Exp $

DISTNAME=	arts-1.4.0
CATEGORIES=	audio
HOMEPAGE=	http://www.kde.org/areas/multimedia/
COMMENT=	Analog Real-Time Synthesizer

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFLICTS+=	kdelibs-2*

USE_PERL5=		build

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

_IN_ARTS_BUILD=		yes
.include "../../meta-pkgs/kde3/kde3.mk"

.if ${OPSYS} == "Linux"
# workaround bug noted in PR #25402
BUILDLINK_TRANSFORM+=	rm:-Wl,--allow-shlib-undefined
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-undefined
.endif

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
