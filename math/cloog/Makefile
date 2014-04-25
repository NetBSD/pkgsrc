# $NetBSD: Makefile,v 1.7 2014/04/25 21:01:27 wiz Exp $

DISTNAME=	cloog-0.18.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/infrastructure/}

MAINTAINER=	kuehro@gmx.de
HOMEPAGE=	http://www.cloog.org/
COMMENT=	Code generator for loop optimization (used by gcc)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

TEST_TARGET=	check

CONFIGURE_ARGS+=	--with-isl=system
CONFIGURE_ARGS+=	--with-bits=gmp

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/isl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
