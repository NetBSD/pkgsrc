# $NetBSD: Makefile,v 1.70 2010/06/16 14:21:38 obache Exp $

DISTNAME=	arts-1.5.10
PKGREVISION=	1
CATEGORIES=	audio
HOMEPAGE=	http://multimedia.kde.org/
COMMENT=	Analog Real-Time Synthesizer

.include "../../meta-pkgs/kde3/Makefile.kde3"

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	kdelibs-2*

USE_TOOLS+=	perl pkg-config

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

_IN_ARTS_BUILD=		yes
.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "options.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threading
.endif

post-patch:
	cd ${FILESDIR} && cp gslglib.* ${WRKSRC}/flow/gsl/

.include "../../mk/bsd.pkg.mk"
