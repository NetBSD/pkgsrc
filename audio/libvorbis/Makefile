# $NetBSD: Makefile,v 1.2 2001/04/04 07:08:28 tron Exp $

DISTNAME=	libvorbis-1.0beta4
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake-1.4:../../devel/automake
DEPENDS+=       libogg>=1.0beta4:../../audio/libogg

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS=		--with-ogg-prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
