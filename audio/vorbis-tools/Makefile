# $NetBSD: Makefile,v 1.1.1.1 2001/03/15 20:53:06 wiz Exp $

DISTNAME=	vorbis-tools-1.0beta4
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.vorbis.com/
COMMENT=	Ogg Vorbis encoder and player

DEPENDS+=	libao>=0.6.0:../../audio/libao
DEPENDS+=	libogg>=1.0beta4:../../audio/libogg
DEPENDS+=	libvorbis>=1.0beta4:../../audio/libvorbis

CONFLICTS=	vorbis-*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ogg-prefix=${PREFIX} \
			--with-vorbis-prefix=${PREFIX} \
			--with-ao-prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
