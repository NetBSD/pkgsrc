# $NetBSD: Makefile,v 1.4 2012/08/05 18:24:56 marino Exp $

DISTNAME=	mpc-1.0
PKGNAME=	mpcomplex-1.0
CATEGORIES=	math
MASTER_SITES=	http://www.multiprecision.org/mpc/download/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://www.multiprecision.org/mpc/
COMMENT=	Multiprecision complex arithmetic library
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT= user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.gmp+=	gmp>=4.3.2
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.4.2
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
