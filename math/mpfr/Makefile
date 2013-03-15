# $NetBSD: Makefile,v 1.26 2013/03/15 19:09:06 drochner Exp $
#

DISTNAME=		mpfr-3.1.2
#PKGNAME=		${DISTNAME}p2	# append patch level
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-3.1.2/
EXTRACT_SUFX=		.tar.bz2

#DIST_SUBDIR=		${DISTNAME}
#PATCH_SITES=		${MASTER_SITES}
#PATCHFILES=		patch01 patch02
#PATCH_DIST_STRIP=	-p1

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations
LICENSE=		gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check # needs the package installed
INFO_FILES=		yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
