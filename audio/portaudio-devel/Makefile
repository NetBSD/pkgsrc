# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:14 joerg Exp $

DISTNAME=	pa_snapshot_v19
PKGNAME=	portaudio-devel-20060521
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/portaudio2
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/portaudio2
CONFIGURE_ARGS+=	--without-alsa
LDFLAGS+=		${LIBOSSAUDIO}
WRKSRC=			${WRKDIR}/portaudio

INSTALLATION_DIRS=	include/portaudio2 lib/portaudio2

post-patch:
	touch ${WRKSRC}/libtool #, so that it gets replaced later

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
