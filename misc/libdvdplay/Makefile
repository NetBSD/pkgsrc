# $NetBSD: Makefile,v 1.4 2004/01/28 03:56:29 grant Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://developers.videolan.org/libdvdplay/
COMMENT=	simple API library designed for DVD navigation

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
