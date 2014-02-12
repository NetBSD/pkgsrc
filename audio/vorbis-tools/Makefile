# $NetBSD: Makefile,v 1.60 2014/02/12 23:17:35 tron Exp $

DISTNAME=	vorbis-tools-1.4.0
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

BUILD_DEFS+=	IPV6_READY

CONFLICTS=	vorbis-[0-9]*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_PREFIX.libogg}
CONFIGURE_ARGS+=	--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis}

PLIST_SUBST+=	DISTNAME=${DISTNAME}

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
