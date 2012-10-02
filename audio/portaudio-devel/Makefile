# $NetBSD: Makefile,v 1.6 2012/10/02 23:48:04 asau Exp $

DISTNAME=	pa_snapshot_v19
PKGNAME=	portaudio-devel-20060521
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBSUBDIR=portaudio2
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/portaudio2
CONFIGURE_ARGS+=	--without-alsa
LDFLAGS+=		${LIBOSSAUDIO}
PKGCONFIG_OVERRIDE=	portaudio-2.0.pc.in
WRKSRC=			${WRKDIR}/portaudio

INSTALLATION_DIRS=	include/portaudio2 lib/portaudio2

post-patch:
	touch ${WRKSRC}/libtool #, so that it gets replaced later

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
