# $NetBSD: Makefile,v 1.7 2004/04/25 02:14:11 snj Exp $
#

DISTNAME=	fplsa
PKGNAME=	gp-fplsa-1.0
PKGREVISION=	1
SVR4_PKGNAME=	gpfpl
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/fplsa.html
COMMENT=	GAP interface to FPLSA

WRKSRC=		${WRKDIR}/fplsa
USE_BUILDLINK3=	YES
GAP_PKG_NAME=	fplsa
ALL_TARGET=	default

do-configure:
	cd ${WRKSRC} && ${SH} configure ${GAP_DIRECTORY}

do-install:
	${INSTALL_PROGRAM_DIR} ${GAP_PKG_DIRECTORY}
	@for I in README.fplsa bin doc gap init.g lib; do		\
		cd ${WRKSRC} && ${PAX} -rw $$I ${GAP_PKG_DIRECTORY}; done

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
