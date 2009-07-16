# $NetBSD: Makefile,v 1.9 2009/07/16 15:17:22 joerg Exp $
#

DISTNAME=		xylem.1.8.7
PKGNAME=		xylem-1.8.7
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.cc.umanitoba.ca/psgendb/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://home.cc.umanitoba.ca/~psgendb/XYLEM.html
COMMENT=		Tools for manipulation of genetic databases

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/xylem
BUILD_DIRS=		src.c # yes, it's a directory
INSTALLATION_DIRS=	bin

do-configure:
	${CP} ${WRKSRC}/src.c/p2c.h.standard ${WRKSRC}/src.c/p2c.h

# Rename some binaries to avoid confusion with base system or conflicts
post-build:
	${RM} -f ${WRKSRC}/test/testxylem.csh.orig
	${MV} ${WRKSRC}/src.c/identify ${WRKSRC}/src.c/xyl-identify
	${MV} ${WRKSRC}/src.c/shuffle ${WRKSRC}/src.c/xyl-shuffle

do-install:
.for PROGRAM in dbstat getloc getob xyl-identify prot2nuc reform ribosome \
	splitdb xyl-shuffle flat2phyl phyl2flat
	${INSTALL_PROGRAM} ${WRKSRC}/src.c/${PROGRAM} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xylem
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/xylem/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/xylem
	${INSTALL_DATA} ${WRKSRC}/test/sample.* \
		${DESTDIR}${PREFIX}/share/examples/xylem
	${INSTALL_SCRIPT} ${WRKSRC}/test/testxylem.csh \
		${DESTDIR}${PREFIX}/share/examples/xylem

.include "../../mk/bsd.pkg.mk"
