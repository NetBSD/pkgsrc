# $NetBSD: Makefile,v 1.23 2012/08/01 19:29:26 drochner Exp $
#

DISTNAME=		mpfr-3.1.1
#PKGNAME=		${DISTNAME}.3	# append patch level
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-3.1.1/
EXTRACT_SUFX=		.tar.bz2

DIST_SUBDIR=		${DISTNAME}
#PATCH_SITES=		${MASTER_SITES}
#PATCHFILES=		patch01 patch02 patch03
#PATCH_DIST_STRIP=	-p1

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations
LICENSE=		gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
