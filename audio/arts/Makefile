# $NetBSD: Makefile,v 1.21 2003/12/08 14:41:38 wiz Exp $

DISTNAME=	arts-1.1.4
CATEGORIES=	audio
COMMENT=	Analog Real-Time Synthesizer
PKGREVISION=	1

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
