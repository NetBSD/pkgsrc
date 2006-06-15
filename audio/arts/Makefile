# $NetBSD: Makefile,v 1.57 2006/06/15 01:33:05 markd Exp $

DISTNAME=	arts-1.5.3
PKGREVISION=	1
CATEGORIES=	audio
HOMEPAGE=	http://www.kde.org/areas/multimedia/
COMMENT=	Analog Real-Time Synthesizer

PATCH_SITES=	ftp://ftp.kde.org/pub/kde/security_patches/
PATCHFILES=	arts-1.2.x.diff

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
