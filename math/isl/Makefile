# $NetBSD: Makefile,v 1.1 2013/02/17 22:10:47 wiz Exp $

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

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
