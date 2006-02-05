# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:02 joerg Exp $
#

DISTNAME=	lag-2.1
PKGNAME=	gp-lag-2.1
PKGREVISION=	1
SVR4_PKGNAME=	gplag
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/lag.html
COMMENT=	GAP Bracket Lie Algebra functions

WRKSRC=		${WRKDIR}/lag
NO_BUILD=	YES
GAP_PKG_NAME=	lag

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
