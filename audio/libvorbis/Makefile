# $NetBSD: Makefile,v 1.1.1.1 2001/03/15 20:39:31 wiz Exp $

DISTNAME=	libvorbis-1.0beta4
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

DEPENDS+=       libogg>=1.0beta4:../../audio/libogg

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS=		--with-ogg-prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
