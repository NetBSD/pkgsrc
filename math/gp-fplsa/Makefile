# $NetBSD: Makefile,v 1.12 2008/05/26 02:13:22 joerg Exp $
#

DISTNAME=	fplsa
PKGNAME=	gp-fplsa-1.0
PKGREVISION=	2
SVR4_PKGNAME=	gpfpl
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/fplsa.html
COMMENT=	GAP interface to FPLSA

PKG_DESTDIR_SUPPORT=	user-destdir

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
