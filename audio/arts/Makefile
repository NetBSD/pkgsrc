# $NetBSD: Makefile,v 1.14 2003/05/02 11:53:37 wiz Exp $

DISTNAME=	arts-1.1.1
PKGREVISION=	1
CATEGORIES=	audio
COMMENT=	Analog Real-Time Synthesizer

.include "../../x11/kde3/Makefile.kde3"

CONFLICTS+=	kdelibs-2*

USE_BUILDLINK2=		yes
USE_PERL5=		build

LIBTOOL_OVERRIDE+=	${WRKSRC}/libltdl/libtool
CONFIGURE_ENV+=		ac_cv_path_PKG_CONFIG=no

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
