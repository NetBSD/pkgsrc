# $NetBSD: Makefile,v 1.50 2008/04/29 05:51:09 wiz Exp $

DISTNAME=	vorbis-tools-1.2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	IPV6_READY

CONFLICTS=	vorbis-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}	\
			--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis} \
			--with-ao-prefix=${BUILDLINK_PREFIX.libao} \
			--enable-vcut

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
