# $NetBSD: Makefile,v 1.105 2026/06/14 17:51:31 nia Exp $

DISTNAME=	vorbis-tools-1.4.3
PKGREVISION=    1
CATEGORIES=	audio
MASTER_SITES=	https://ftp.osuosl.org/pub/xiph/releases/vorbis/

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player
LICENSE=	gnu-gpl-v2

CONFLICTS=	vorbis-[0-9]*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# Uses "old-style function definitions" in getopt support files.
FORCE_C_STD=		gnu89

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
