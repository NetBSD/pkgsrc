# $NetBSD: Makefile,v 1.16 2012/09/11 23:04:34 asau Exp $

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

USE_BSD_MAKEFILE=	yes
MAKE_FLAGS+=		MKPROFILE=yes
INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	share/doc/tasp-vsipl

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	cd ${WRKDIR}/${DISTNAME} && ${INSTALL_DATA} Copyright	\
		README_FIRST *.pdf ${DESTDIR}${PREFIX}/share/doc/tasp-vsipl

do-test:
	cd ${WRKDIR}/${DISTNAME}/testing && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
