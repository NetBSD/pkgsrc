# $NetBSD: Makefile,v 1.1.1.1 2002/12/22 18:29:17 cjep Exp $
#

DISTNAME=	lag-2.1
PKGNAME=	gp-lag-2.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://www.gap-system.org/Share/lag.html
COMMENT=	GAP Bracket Lie Algebra functions

BUILD_DEPENDS+= zoo-[0-9]*:../../archivers/zoo

EXTRACT_CMD=    ${LOCALBASE}/bin/zoo -extract ${DOWNLOADED_DISTFILE}
WRKSRC=		${WRKDIR}/lag

NO_BUILD=	YES
USE_BUILDLINK2=	YES
GAP_PKG_NAME=	lag

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
