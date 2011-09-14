# $NetBSD: Makefile,v 1.3 2011/09/14 17:14:09 hans Exp $

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

BUILDLINK_API_DEPENDS.gmp+=	gmp>=4.3.2
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.4.2
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
