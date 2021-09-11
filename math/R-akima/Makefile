# $NetBSD: Makefile,v 1.17 2021/09/11 10:19:37 mef Exp $

R_PKGNAME=	akima
R_PKGVER=	0.6-2.2

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
