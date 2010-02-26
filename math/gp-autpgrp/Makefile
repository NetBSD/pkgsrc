# $NetBSD: Makefile,v 1.12 2010/02/26 10:28:32 wiz Exp $
#

DISTNAME=	autpgrp-1.1
PKGNAME=	gp-autpgrp-1.1
PKGREVISION=	1
SVR4_PKGNAME=	gpapg
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/autpgrp.html
COMMENT=	GAP package for finding automorphism groups of finite p-groups

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/autpgrp
NO_BUILD=	YES
GAP_PKG_NAME=	autpgrp

USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GAP_PKG_ROOT}
	cd ${WRKDIR} && pax -rw ${GAP_PKG_NAME} ${DESTDIR}${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
