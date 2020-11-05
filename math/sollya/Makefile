# $NetBSD: Makefile,v 1.3 2020/11/05 09:08:38 ryoon Exp $

DISTNAME=	sollya-7.0
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/37749/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sollya.gforge.inria.fr/
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
