# $NetBSD: Makefile,v 1.8 2006/03/31 23:56:28 jlam Exp $
#

DISTNAME=		mpfr-2.2.0
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-current/

DIST_SUBDIR=		mpfr-2.2.0-060221
PATCH_SITES=		http://www.mpfr.org/mpfr-current/
PATCHFILES=		patches
PATCH_DIST_STRIP=	-p1

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		# PLIST

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
