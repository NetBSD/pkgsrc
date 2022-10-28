# $NetBSD: Makefile,v 1.7 2022/10/28 19:59:03 alnsn Exp $

DISTNAME=	sollya-7.0
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	https://www.sollya.org/releases/sollya-7.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sollya.org/
COMMENT=	Environment and library for safe floating-point code development
LICENSE=	cecill-2.0 AND gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/fplll/buildlink3.mk"
.include "../../math/mpfi/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
