# $NetBSD: Makefile,v 1.4 2002/12/23 22:18:24 cjep Exp $
#

DISTNAME=	grape4r1
PKGNAME=	gp-grape-4.1
CATEGORIES=	math
MASTER_SITES=	http://www.maths.qmul.ac.uk/~leonard/grape4r1/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://www.gap-system.org/Share/grape.html
COMMENT=	GRAPE (GRape Algorithms using PErmutation groups)

WRKSRC=		${WRKDIR}/${GAP_PKG_NAME}

ALL_TARGET=	bsd-gcc

GAP_PKG_NAME=	grape

do-configure:
	cd ${WRKSRC} && ${SH} configure ${GAP_DIRECTORY}

do-install:
	${INSTALL_PROGRAM_DIR} ${GAP_PKG_DIRECTORY}
	@for I in COPYING bin doc grh htm init.g lib nauty20/read.me 	\
					prs; do				\
		${CP} -R ${WRKSRC}/$$I ${GAP_PKG_DIRECTORY};		\
	done

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
