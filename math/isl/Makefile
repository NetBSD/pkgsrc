# $NetBSD: Makefile,v 1.2 2013/02/19 19:45:44 wiz Exp $

DISTNAME=	isl-0.11.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/infrastructure/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integer set library required by gcc graphite
HOMEPAGE=	http://repo.or.cz/w/isl.git
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmpl}

TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
