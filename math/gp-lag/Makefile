# $NetBSD: Makefile,v 1.13 2012/09/11 23:04:21 asau Exp $
#

DISTNAME=	lag-2.1
PKGNAME=	gp-lag-2.1
PKGREVISION=	1
SVR4_PKGNAME=	gplag
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/lag.html
COMMENT=	GAP Bracket Lie Algebra functions

WRKSRC=		${WRKDIR}/lag
NO_BUILD=	YES
GAP_PKG_NAME=	lag

USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GAP_PKG_ROOT}
	cd ${WRKDIR} && pax -rw ${GAP_PKG_NAME} ${DESTDIR}${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
