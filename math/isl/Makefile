# $NetBSD: Makefile,v 1.3 2013/04/16 06:47:15 adam Exp $

DISTNAME=	isl-0.11.2
CATEGORIES=	math
MASTER_SITES=	http://garage.kotnet.org/~skimo/isl/ \
		${MASTER_SITE_GNU:=gcc/infrastructure/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://garage.kotnet.org/~skimo/isl/
COMMENT=	Integer set library required by gcc graphite
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmpl}

TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
