# $NetBSD: Makefile,v 1.1.1.1 2003/01/05 13:58:11 cjep Exp $
#

DISTNAME=	grpconst
PKGNAME=	gp-grpconst-2.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://www.gap-system.org/Share/grpconst.html
COMMENT=	GAP package for finding isomorphism classes of finite groups

WRKSRC=		${WRKDIR}/grpconst

NO_BUILD=	YES
USE_BUILDLINK2=	YES
GAP_PKG_NAME=	grpconst

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
