# $NetBSD: Makefile,v 1.5 2003/07/17 21:47:36 grant Exp $
#

DISTNAME=	factint-1.3
PKGNAME=	gp-factint-1.3
SVR4_PKGNAME=	gpfin
WRKSRC=		${WRKDIR}/factint
CATEGORIES=	math
MASTER_SITES=	http://www.cip.mathematik.uni-stuttgart.de/~kohlsn/factint/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/factint.html
COMMENT=	Integer factorization routines for GAP

NO_BUILD=	YES
USE_BUILDLINK2=	YES
GAP_PKG_NAME=	factint

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
