# $NetBSD: Makefile,v 1.4 2002/07/24 19:45:22 jlam Exp $

DISTNAME=	arts-1.0.2
CATEGORIES=	audio
COMMENT=	Analog Real-Time Synthesizer

.include "../../x11/kde3/Makefile.kde3"

CONFLICTS+=	kdelibs-2*

USE_BUILDLINK_ONLY=	yes

LIBTOOL_OVERRIDE+=	${WRKSRC}/libltdl/libtool

USE_PERL5=		build
USE_PTHREAD=		native pth-syscall
.include "../../mk/bsd.prefs.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-threading
.endif

.if ${OPSYS} == "NetBSD"
LIBS+=			-Wl,--export-dynamic
.endif

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
