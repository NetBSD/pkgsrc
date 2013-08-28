# $NetBSD: Makefile,v 1.11 2013/08/28 12:34:59 fhajny Exp $

DISTNAME=	libev-4.15
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	2-clause-bsd OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
#TEST_TARGET=	verify

GNU_CONFIGURE_LIBSUBDIR=ev
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ev

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
