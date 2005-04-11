# $NetBSD: Makefile,v 1.8 2005/04/11 21:46:29 tv Exp $
#

DISTNAME=	grpconst
PKGNAME=	gp-grpconst-2.0
SVR4_PKGNAME=	gpgct
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/grpconst.html
COMMENT=	GAP package for finding isomorphism classes of finite groups

WRKSRC=		${WRKDIR}/grpconst
NO_BUILD=	YES
GAP_PKG_NAME=	grpconst

post-extract:
	${RM} -f ${WRKSRC}/doc/.cvsignore

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
