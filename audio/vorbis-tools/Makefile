# $NetBSD: Makefile,v 1.27 2003/12/08 14:43:48 wiz Exp $

DISTNAME=	vorbis-tools-1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/1.0.1/unix/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

CONFLICTS=	vorbis-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}	\
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis} \
			--with-ao-prefix=${BUILDLINK_PREFIX.libao}

PLIST_SUBST+=	DISTNAME="${DISTNAME}"

PTHREAD_OPTS+=	require

.include "../../audio/flac/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/speex/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
