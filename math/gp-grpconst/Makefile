# $NetBSD: Makefile,v 1.7 2004/04/25 02:14:27 snj Exp $
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
NO_BUILDLINK=	YES
GAP_PKG_NAME=	grpconst

post-extract:
	${RM} -f ${WRKSRC}/doc/.cvsignore

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
