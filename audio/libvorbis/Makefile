# $NetBSD: Makefile,v 1.5 2001/06/26 13:07:37 zuntum Exp $

DISTNAME=	libvorbis-1.0beta4
PKGNAME=	libvorbis-1.0.0.4
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

USE_BUILDLINK_ONLY=	YES
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake-1.4:../../devel/automake

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.include "../../audio/libogg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
