# $NetBSD: Makefile,v 1.5 2013/11/16 19:31:30 mspo Exp $

DISTNAME=	snappy-1.1.1
CATEGORIES=	devel
MASTER_SITES=	http://snappy.googlecode.com/files/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
