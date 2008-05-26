# $NetBSD: Makefile,v 1.11 2008/05/26 02:13:22 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/grpconst
NO_BUILD=	YES
GAP_PKG_NAME=	grpconst

USE_TOOLS+=	pax

post-extract:
	${RM} -f ${WRKSRC}/doc/.cvsignore

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GAP_PKG_ROOT}
	cd ${WRKDIR} && pax -rw ${GAP_PKG_NAME} ${DESTDIR}${GAP_PKG_ROOT}

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
