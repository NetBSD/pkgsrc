# $NetBSD: Makefile,v 1.4 2013/02/09 21:36:02 wiz Exp $
#

DISTNAME=	cloog-0.18.0
CATEGORIES=	math
MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/infrastructure/

MAINTAINER=	kuehro@gmx.de
HOMEPAGE=	http://www.cloog.org/
COMMENT=	Code generator for loop optimization (used by gcc)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
