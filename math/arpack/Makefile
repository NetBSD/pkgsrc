# $NetBSD: Makefile,v 1.2 2012/09/11 23:04:16 asau Exp $

DISTNAME=	arpack96
PKGNAME=	arpack-96
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	arpack96.tar.gz patch.tar.gz

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://www.caam.rice.edu/software/ARPACK/SRC/
COMMENT=	Library of subroutines to solve eigenvalue problems
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/ARPACK
USE_LANGUAGES=	fortran77
MAKE_ENV+=	WRKSRC=${WRKSRC}

INSTALLATION_DIRS=	lib

# Patches must be extracted AFTER the main dist to overwrite files
post-extract:
	cd ${WRKDIR} && ${TAR} -zxf ${DISTDIR}/patch.tar.gz

do-install:
	${INSTALL_DATA} ${WRKSRC}/libarpack.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
