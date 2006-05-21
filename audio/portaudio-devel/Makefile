# $NetBSD: Makefile,v 1.1.1.1 2006/05/21 22:21:10 ben Exp $

DISTNAME=	pa_snapshot_v19
PKGNAME=	portaudio-devel-20060521
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
WRKSRC=		${WRKDIR}/portaudio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API

NOT_FOR_PLATFORM=	Interix-*-*

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/portaudio2
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/portaudio2
CONFIGURE_ARGS+=	--without-alsa
LDFLAGS+=		${LIBOSSAUDIO}

post-patch:
	${TOUCH} ${WRKSRC}/libtool

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/portaudio2
	${INSTALL_DATA_DIR} ${PREFIX}/lib/portaudio2

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
