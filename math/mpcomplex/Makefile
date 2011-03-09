# $NetBSD: Makefile,v 1.2 2011/03/09 18:59:46 asau Exp $

DISTNAME=	mpc-0.9
PKGNAME=	mpcomplex-0.9
CATEGORIES=	math
MASTER_SITES=	http://www.multiprecision.org/mpc/download/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://www.multiprecision.org/mpc/
COMMENT=	Multiprecision complex arithmetic library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT= user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

TEST_TARGET=	check

.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
