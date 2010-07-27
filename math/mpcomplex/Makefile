# $NetBSD: Makefile,v 1.1.1.1 2010/07/27 17:09:45 asau Exp $

DISTNAME=	mpc-0.8.2
PKGNAME=	mpcomplex-0.8.2
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
