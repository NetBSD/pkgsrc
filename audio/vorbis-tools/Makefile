# $NetBSD: Makefile,v 1.3 2001/08/08 10:05:30 lukem Exp $

DISTNAME=	vorbis-tools-1.0rc1
PKGNAME=	vorbis-tools-1.0.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc1/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

CONFLICTS=	vorbis-*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ogg-prefix=${PREFIX} \
			--with-vorbis-prefix=${PREFIX} \
			--with-ao-prefix=${PREFIX}

.include "../../audio/libao/buildlink.mk"
.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
