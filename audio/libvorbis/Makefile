# $NetBSD: Makefile,v 1.3 2001/04/05 13:18:52 wiz Exp $

DISTNAME=	libvorbis-1.0beta4
PKGNAME=	libvorbis-1.0.0.4
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake-1.4:../../devel/automake
DEPENDS+=       libogg>=1.0.0.4:../../audio/libogg

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS=		--with-ogg-prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
