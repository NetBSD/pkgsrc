# $NetBSD: Makefile,v 1.10 2021/05/02 17:47:30 adam Exp $

DISTNAME=	isl-0.24
CATEGORIES=	math
MASTER_SITES=	http://isl.gforge.inria.fr/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://isl.gforge.inria.fr/
COMMENT=	Integer set library required by gcc graphite
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
