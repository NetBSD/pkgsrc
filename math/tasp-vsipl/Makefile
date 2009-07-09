# $NetBSD: Makefile,v 1.11.24.1 2009/07/09 09:32:43 tron Exp $

DISTNAME=	tvcpp0p8
PKGNAME=	tasp-vsipl-20030710
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.vsipl.org/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vsipl.org/
COMMENT=	Vector Signal Image Processing Library

WRKSRC=		${WRKDIR}/${DISTNAME}/lib
DIST_SUBDIR=	tasp-vsipl

INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	share/doc/tasp-vsipl

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	cd ${WRKDIR}/${DISTNAME} && ${INSTALL_DATA} Copyright	\
		README_FIRST *.pdf ${PREFIX}/share/doc/tasp-vsipl

do-test:
	cd ${WRKDIR}/${DISTNAME}/testing && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
