# $NetBSD: Makefile,v 1.29 2015/06/30 10:25:01 ryoon Exp $

DISTNAME=		mpfr-3.1.3
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-3.1.3/
EXTRACT_SUFX=		.tar.bz2

DIST_SUBDIR=		${DISTNAME}

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
