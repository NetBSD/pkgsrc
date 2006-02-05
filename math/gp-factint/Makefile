# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:02 joerg Exp $
#

DISTNAME=	factint-1.3
PKGNAME=	gp-factint-1.3
PKGREVISION=	1
SVR4_PKGNAME=	gpfin
CATEGORIES=	math
MASTER_SITES=	http://www.cip.mathematik.uni-stuttgart.de/~kohlsn/factint/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/factint.html
COMMENT=	Integer factorization routines for GAP

WRKSRC=		${WRKDIR}/factint
NO_BUILD=	YES
GAP_PKG_NAME=	factint

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
