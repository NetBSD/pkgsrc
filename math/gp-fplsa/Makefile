# $NetBSD: Makefile,v 1.2 2003/01/05 12:43:02 cjep Exp $
#

DISTNAME=	fplsa
PKGNAME=	gp-fplsa-1.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://www.gap-system.org/Share/fplsa.html
COMMENT=	GAP interface to FPLSA

WRKSRC=		${WRKDIR}/fplsa

USE_BUILDLINK2=	YES
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
