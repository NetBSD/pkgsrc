# $NetBSD: Makefile,v 1.39 2006/02/05 23:08:14 joerg Exp $

DISTNAME=	vorbis-tools-1.1.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

CONFLICTS=	vorbis-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}	\
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis} \
			--with-ao-prefix=${BUILDLINK_PREFIX.libao}

PLIST_SUBST+=	DISTNAME=${DISTNAME:Q}

PTHREAD_OPTS+=	require

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
