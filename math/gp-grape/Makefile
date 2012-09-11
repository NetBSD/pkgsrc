# $NetBSD: Makefile,v 1.14 2012/09/11 23:04:21 asau Exp $
#

DISTNAME=	grape4r1
PKGNAME=	gp-grape-4.1
PKGREVISION=	2
SVR4_PKGNAME=	gpgra
CATEGORIES=	math
MASTER_SITES=	http://www.maths.qmul.ac.uk/~leonard/grape4r1/
EXTRACT_SUFX=	.zoo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/grape.html
COMMENT=	GRAPE (GRape Algorithms using PErmutation groups)

BUILD_TARGET=	bsd-gcc

WRKSRC=		${WRKDIR}/${GAP_PKG_NAME}
GAP_PKG_NAME=	grape

do-configure:
	cd ${WRKSRC} && ${SH} configure ${GAP_DIRECTORY}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${GAP_PKG_DIRECTORY}
	@for I in COPYING bin doc grh htm init.g lib nauty20/read.me 	\
					prs; do				\
		${CP} -R ${WRKSRC}/$$I ${DESTDIR}${GAP_PKG_DIRECTORY};	\
	done

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
