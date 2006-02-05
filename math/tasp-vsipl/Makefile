# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:04 joerg Exp $

DISTNAME=	tvcpp0p8
PKGNAME=	tasp-vsipl-20030710
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.vsipl.org/software/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.vsipl.org/
COMMENT=	Vector Signal Image Processing Library

WRKSRC=		${WRKDIR}/${DISTNAME}/lib
DIST_SUBDIR=	tasp-vsipl


.include "../../mk/x11.buildlink3.mk"

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tasp-vsipl
	cd ${WRKSRC}/../ && ${INSTALL_DATA} Copyright	\
		README_FIRST *.pdf ${PREFIX}/share/doc/tasp-vsipl

do-test:
	@cd ${WRKSRC}/../testing && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include "../../mk/bsd.pkg.mk"
