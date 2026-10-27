# $NetBSD: Makefile,v 1.1 2026/10/27 19:47:41 drixter Exp $

DISTNAME=	4ti2-1.6.15
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=4ti2/}
GITHUB_PROJECT=	4ti2
GITHUB_RELEASE=	Release_1_6_15

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://4ti2.github.io/
COMMENT=	Solve algebraic, geometric, combinatorial problems on linear spaces
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--disable-groebner
CONFIGURE_ARGS+=	--disable-zsolve
CONFIGURE_ARGS+=	--disable-fiber

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++ fortran

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
