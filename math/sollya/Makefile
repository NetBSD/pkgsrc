# $NetBSD: Makefile,v 1.9 2022/11/23 16:20:36 adam Exp $

DISTNAME=	sollya-8.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.sollya.org/releases/sollya-8.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sollya.org/
COMMENT=	Environment and library for safe floating-point code development
LICENSE=	cecill-2.0 AND gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-xml2-include=${PREFIX}/include/libxml2

TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/fplll/buildlink3.mk"
.include "../../math/mpfi/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
