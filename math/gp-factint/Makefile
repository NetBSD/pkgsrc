# $NetBSD: Makefile,v 1.1.1.1 2002/12/23 01:26:24 cjep Exp $
#

DISTNAME=	factint-1.3
PKGNAME=	gp-factint-1.3
CATEGORIES=	math
MASTER_SITES=	http://www.cip.mathematik.uni-stuttgart.de/~kohlsn/factint/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://www.gap-system.org/Share/factint.html
COMMENT=	Integer factorization routines for GAP

BUILD_DEPENDS+=	zoo-[0-9]*:../../archivers/zoo

EXTRACT_CMD=	${LOCALBASE}/bin/zoo -extract ${DOWNLOADED_DISTFILE}
WRKSRC=		${WRKDIR}/factint

NO_BUILD=	YES
USE_BUILDLINK2=	YES
GAP_PKG_NAME=	factint

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
