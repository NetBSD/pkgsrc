# $NetBSD: Makefile,v 1.34 2012/09/11 23:04:22 asau Exp $

DISTNAME=	lapack-lite-3.1.1
PKGNAME=	lapack-3.1.1
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_NETLIB:=lapack/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/lapack/index.html
COMMENT=	Linear Algebra PACKage
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		YES
BUILD_TARGET=		lapacklib

INSTALLATION_DIRS=	lib

FFLAGS+=		-ffloat-store

# With f2c-20090411nb4, libf2c-20090201nb3, we need EXT_ETIME but gcc44-4.4.1nb3
# needs INT_ETIME.  Rather than trying to enumerate all possible fortran
# compilers, just do a test for it.
do-configure:
	@${ECHO_N} "Checking if your fortran compiler has etime() as an intrinsic... "
	${FC} -o ${WRKDIR}/etime_test ${FILESDIR}/etime_test.f >${WRKDIR}/etime_test.log 2>&1; \
	if ${TEST} $$? -eq 0 ; then \
	${ECHO} "TIMER=INT_ETIME" >> ${WRKSRC}/make.inc ; ${ECHO} "YES" ; else \
	${ECHO} "TIMER=EXT_ETIME" >> ${WRKSRC}/make.inc ; ${ECHO} "NO" ; fi
	@${ECHO} "See ${WRKDIR}/etime_test.log for details on the test"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/liblapack.la \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
