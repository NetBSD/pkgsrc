# $NetBSD: Makefile,v 1.10 2020/03/21 11:50:10 rillig Exp $

DISTNAME=	cloog-0.18.4
CATEGORIES=	math
MASTER_SITES=	http://www.bastoul.net/cloog/pages/download/

MAINTAINER=	kuehro@gmx.de
HOMEPAGE=	https://www.cloog.org/
COMMENT=	Code generator for loop optimization (used by gcc)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

TEST_TARGET=	check

CONFIGURE_ARGS+=	--with-isl=system

BUILDLINK_API_DEPENDS.gmp+=	gmp>=6.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/isl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
