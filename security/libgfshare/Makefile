# $NetBSD: Makefile,v 1.3 2022/11/21 18:20:44 jperkin Exp $

DISTNAME=	libgfshare-1.0.5
CATEGORIES=	security
MASTER_SITES=	http://www.digital-scurf.org/files/libgfshare/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.digital-scurf.org/software/libgfshare
COMMENT=	Library to implement Shamir's secret sharing scheme
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-O1

.include "../../mk/bsd.pkg.mk"
