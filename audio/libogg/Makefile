# $NetBSD: Makefile,v 1.3 2001/04/11 08:59:09 tron Exp $

DISTNAME=	libogg-1.0beta4
PKGNAME=	libogg-1.0.0.4
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.include "../../mk/bsd.pkg.mk"
