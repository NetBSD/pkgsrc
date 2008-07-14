# $NetBSD: Makefile,v 1.10 2008/07/14 12:56:08 joerg Exp $
#

DISTNAME=		mpfr-2.3.0
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-current/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		# PLIST

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
