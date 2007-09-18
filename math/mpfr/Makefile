# $NetBSD: Makefile,v 1.9 2007/09/18 20:15:57 drochner Exp $
#

DISTNAME=		mpfr-2.3.0
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-current/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		# PLIST

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
