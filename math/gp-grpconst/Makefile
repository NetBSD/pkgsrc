# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:02 joerg Exp $
#

DISTNAME=	grpconst
PKGNAME=	gp-grpconst-2.0
PKGREVISION=	1
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
