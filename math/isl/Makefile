# $NetBSD: Makefile,v 1.11 2023/05/03 18:16:47 wiz Exp $

DISTNAME=	isl-0.24
CATEGORIES=	math
MASTER_SITES=	https://libisl.sourceforge.io/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libisl.sourceforge.io/
COMMENT=	Integer set library required by gcc graphite
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
