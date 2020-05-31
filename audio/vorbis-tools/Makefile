# $NetBSD: Makefile,v 1.81 2020/05/31 17:37:36 rillig Exp $

DISTNAME=	vorbis-tools-1.4.0
PKGREVISION=	23
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=	IPV6_READY

CONFLICTS=	vorbis-[0-9]*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

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
