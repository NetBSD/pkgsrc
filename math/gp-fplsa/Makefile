# $NetBSD: Makefile,v 1.14 2012/09/11 23:04:21 asau Exp $
#

DISTNAME=	fplsa
PKGNAME=	gp-fplsa-1.0
PKGREVISION=	2
SVR4_PKGNAME=	gpfpl
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/fplsa.html
COMMENT=	GAP interface to FPLSA

WRKSRC=		${WRKDIR}/fplsa
GAP_PKG_NAME=	fplsa
BUILD_TARGET=	default

USE_TOOLS+=	pax

do-configure:
	cd ${WRKSRC} && ${SH} configure ${GAP_DIRECTORY}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${GAP_PKG_DIRECTORY}
	@for I in README.fplsa bin doc gap init.g lib; do		\
		cd ${WRKSRC} && pax -rw $$I ${DESTDIR}${GAP_PKG_DIRECTORY};\
	done

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
