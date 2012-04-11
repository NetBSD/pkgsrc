# $NetBSD: Makefile,v 1.2 2012/04/11 21:22:00 wiz Exp $
#

DISTNAME=	cloog-0.16.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/infrastructure/

MAINTAINER=	kuehro@gmx.de
HOMEPAGE=	http://www.cloog.org/
COMMENT=	Code generator for loop optimization (used by gcc)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
