# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:45 jmmv Exp $

DISTNAME=	tvcp012401
PKGNAME=	tasp-vsipl-20010516
WRKSRC=		${WRKDIR}/TASP_VSIPL_Core_Plus/build.${MACHINE_ARCH}
CATEGORIES=	math
MASTER_SITES=	http://www.vsipl.org/

MAINTAINER=	packages@netbsd.org
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
