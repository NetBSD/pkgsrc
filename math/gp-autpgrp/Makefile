# $NetBSD: Makefile,v 1.1.1.1 2002/12/22 18:28:33 cjep Exp $
#

DISTNAME=	autpgrp-1.1
PKGNAME=	gp-autpgrp-1.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://www.gap-system.org/Share/autpgrp.html
COMMENT=	GAP package for finding automorphism groups of finite p-groups

BUILD_DEPENDS+=	zoo-[0-9]*:../../archivers/zoo

EXTRACT_CMD=    ${LOCALBASE}/bin/zoo -extract ${DOWNLOADED_DISTFILE}
WRKSRC=		${WRKDIR}/autpgrp

NO_BUILD=	YES
USE_BUILDLINK2=	YES
GAP_PKG_NAME=	autpgrp

do-install:
	cd ${WRKDIR} && ${PAX} -rw ${GAP_PKG_NAME} ${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
