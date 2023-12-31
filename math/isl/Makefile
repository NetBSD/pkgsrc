# $NetBSD: Makefile,v 1.12 2023/12/31 09:51:42 wiz Exp $

DISTNAME=	isl-0.26
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
