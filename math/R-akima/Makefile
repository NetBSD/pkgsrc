# $NetBSD: Makefile,v 1.13 2018/07/28 14:40:47 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/akima/
COMMENT=	Linear or cubic spline interpolation for irregular gridded data
LICENSE=	acm-license

DEPENDS+=	R-sp>=0:../../math/R-sp

R_PKGNAME=	akima
R_PKGVER=	0.6-2

# Note: the ACM license requires notification prior to distribution of
# modified versions of this package.  If patches are required, then to
# comply with this NO_BIN_ON_FTP and NO_SRC_ON_FTP must be defined.

# Note: the ACM license requires prior arrangements to distribute the
# software as part of a commercial product.
NO_BIN_ON_CDROM=	# defined
NO_SRC_ON_CDROM=	# defined

USE_LANGUAGES=	fortran c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
