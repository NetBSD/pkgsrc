# $NetBSD: Makefile,v 1.7 2015/04/10 01:54:45 mef Exp $

DISTNAME=	isl-0.14.1
CATEGORIES=	math
MASTER_SITES=	http://isl.gforge.inria.fr/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://isl.gforge.inria.fr/
COMMENT=	Integer set library required by gcc graphite
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
