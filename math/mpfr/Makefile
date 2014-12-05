# $NetBSD: Makefile,v 1.28 2014/12/05 13:16:26 wiz Exp $

DISTNAME=		mpfr-3.1.2
PKGNAME=		${DISTNAME}pl11	# append patch level
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-3.1.2/
EXTRACT_SUFX=		.tar.bz2

DIST_SUBDIR=		${DISTNAME}
PATCH_SITES=		${MASTER_SITES}
PATCH_SITES=		http://www.mpfr.org/mpfr-current/
PATCHFILES=		patch01 patch02 patch03 patch04 patch05 patch06 patch07 patch08 patch09 patch10 patch11
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations
LICENSE=		gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
