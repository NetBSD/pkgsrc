# $NetBSD: Makefile,v 1.4.10.1 2017/04/23 10:05:48 bsiegert Exp $

DISTNAME=	arpack96
PKGNAME=	arpack-96
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	arpack96.tar.gz patch.tar.gz

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://www.caam.rice.edu/software/ARPACK/SRC/
COMMENT=	Library of subroutines to solve eigenvalue problems
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/ARPACK
USE_LANGUAGES=	fortran77
MAKE_FILE=	${FILESDIR}/Makefile

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	lib

# Patches must be extracted AFTER the main dist to overwrite files
post-extract:
	cd ${WRKDIR} && ${TAR} -zxf ${DISTDIR}/patch.tar.gz

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libarpack.la ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
