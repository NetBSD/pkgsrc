# $NetBSD: Makefile,v 1.16 2010/03/24 19:43:26 asau Exp $
#

DISTNAME=		mpfr-2.4.2
PKGNAME=		${DISTNAME}.3	# append patch level
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		http://www.mpfr.org/mpfr-current/

DIST_SUBDIR=		${DISTNAME}
PATCHFILES=		patch01 patch02 patch03
PATCH_SITES=		${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.mpfr.org/
COMMENT=		GMP-based library for multiple-precision floating-point computations
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check
INFO_FILES=		yes
###
### XXX These definitions are defined here merely to keep configure from
###	needlessly whining about them.
###
###
MAKE_ENV+=		AUTOCONF=${TRUE}
MAKE_ENV+=		AUTOMAKE=${TRUE}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
