# $NetBSD: Makefile,v 1.3 2003/06/02 01:18:22 jschauma Exp $

DISTNAME=	tvcp012401
PKGNAME=	tasp-vsipl-20010516
WRKSRC=		${WRKDIR}/TASP_VSIPL_Core_Plus/build.${MACHINE_ARCH}
CATEGORIES=	math
MASTER_SITES=	http://www.vsipl.org/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.vsipl.org/
COMMENT=	Vector Signal Image Processing Library

DIST_SUBDIR=	tasp-vsipl

USE_X11=	yes

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tasp-vsipl
	cd ${WRKDIR}/TASP_VSIPL_Core_Plus/ && ${INSTALL_DATA} Copyright	\
		README_FIRST *.pdf ${PREFIX}/share/doc/tasp-vsipl

.include "../../mk/bsd.pkg.mk"
