# $NetBSD: Makefile,v 1.58 2006/08/02 13:39:00 markd Exp $

DISTNAME=	arts-1.5.4
CATEGORIES=	audio
HOMEPAGE=	http://www.kde.org/areas/multimedia/
COMMENT=	Analog Real-Time Synthesizer

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

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
