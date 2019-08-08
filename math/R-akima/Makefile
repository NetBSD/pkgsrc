# $NetBSD: Makefile,v 1.15 2019/08/08 19:53:47 brook Exp $

R_PKGNAME=	akima
R_PKGVER=	0.6-2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interpolation of irregularly and regularly spaced data
LICENSE=	acm-license

DEPENDS+=	R-sp>=1.3.1:../../math/R-sp

# Note: the ACM license requires notification prior to distribution of
# modified versions of this package.  If patches are required, then to
# comply with this NO_BIN_ON_FTP and NO_SRC_ON_FTP must be defined.

# Note: the ACM license requires prior arrangements to distribute the
# software as part of a commercial product.
RESTRICTED=		Prior arrangements required to distribute commercially
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

USE_LANGUAGES=	fortran c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
