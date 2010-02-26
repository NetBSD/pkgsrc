# $NetBSD: Makefile,v 1.12 2010/02/26 10:28:32 wiz Exp $
#

DISTNAME=	factint-1.3
PKGNAME=	gp-factint-1.3
PKGREVISION=	1
SVR4_PKGNAME=	gpfin
CATEGORIES=	math
MASTER_SITES=	http://www.cip.mathematik.uni-stuttgart.de/~kohlsn/factint/
EXTRACT_SUFX=	.zoo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/factint.html
COMMENT=	Integer factorization routines for GAP

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/factint
NO_BUILD=	YES
GAP_PKG_NAME=	factint

USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GAP_PKG_ROOT}
	cd ${WRKDIR} && pax -rw ${GAP_PKG_NAME} ${DESTDIR}${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
