# $NetBSD: Makefile,v 1.11 2008/05/26 02:13:22 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/lag
NO_BUILD=	YES
GAP_PKG_NAME=	lag

USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GAP_PKG_ROOT}
	cd ${WRKDIR} && pax -rw ${GAP_PKG_NAME} ${DESTDIR}${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
