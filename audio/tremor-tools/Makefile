# $NetBSD: Makefile,v 1.17 2005/10/08 12:35:14 jmmv Exp $

DISTNAME=	vorbis-tools-1.0
PKGNAME=	tremor-tools-1.0.0.8
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/1.0/unix/

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

CONFLICTS=	vorbis-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		automake14 gmake
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}	\
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis} \
			--with-ao-prefix=${BUILDLINK_PREFIX.libao}

PLIST_SUBST+=	DISTNAME="${DISTNAME}"

PTHREAD_OPTS+=	require

pre-configure:
	cd ${WRKSRC} && automake && autoconf

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/tremor/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
