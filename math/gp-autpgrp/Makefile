# $NetBSD: Makefile,v 1.6 2004/01/20 12:20:04 agc Exp $
#

DISTNAME=	autpgrp-1.1
PKGNAME=	gp-autpgrp-1.1
SVR4_PKGNAME=	gpapg
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/autpgrp.html
COMMENT=	GAP package for finding automorphism groups of finite p-groups

WRKSRC=		${WRKDIR}/autpgrp
NO_BUILD=	YES
USE_BUILDLINK2=	YES
GAP_PKG_NAME=	autpgrp

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
