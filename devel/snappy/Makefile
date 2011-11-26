# $NetBSD: Makefile,v 1.2 2011/11/26 04:39:47 sbd Exp $

DISTNAME=	snappy-1.0.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://snappy.googlecode.com/files/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
