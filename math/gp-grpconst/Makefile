# $NetBSD: Makefile,v 1.4 2003/07/17 21:47:38 grant Exp $
#

DISTNAME=	grpconst
PKGNAME=	gp-grpconst-2.0
SVR4_PKGNAME=	gpgct
WRKSRC=		${WRKDIR}/grpconst
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/grpconst.html
COMMENT=	GAP package for finding isomorphism classes of finite groups

NO_BUILD=	YES
USE_BUILDLINK2=	YES
GAP_PKG_NAME=	grpconst

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
