# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:41 jlam Exp $
#

DISTNAME=		xylem.1.8.7
PKGNAME=		xylem-1.8.7
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.cc.umanitoba.ca/psgendb/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://home.cc.umanitoba.ca/~psgendb/XYLEM.html
COMMENT=		Tools for manipulation of genetic databases

WRKSRC=                 ${WRKDIR}/xylem/src.c
INSTALLATION_DIRS=	bin

do-configure:
	${CP} ${WRKSRC}/p2c.h.standard ${WRKSRC}/p2c.h

# Rename some binaries to avoid confusion with base system or conflicts
post-build:
	${RM} -f ${WRKSRC}/../test/testxylem.csh.orig
	${MV} ${WRKSRC}/identify ${WRKSRC}/xyl-identify
	${MV} ${WRKSRC}/shuffle ${WRKSRC}/xyl-shuffle

do-install:
.for PROGRAM in dbstat getloc getob xyl-identify prot2nuc reform ribosome \
	splitdb xyl-shuffle flat2phyl phyl2flat
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xylem
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/xylem/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xylem
	${INSTALL_DATA} ${WRKSRC}/../test/sample.* ${PREFIX}/share/examples/xylem
	${INSTALL_SCRIPT} ${WRKSRC}/../test/testxylem.csh ${PREFIX}/share/examples/xylem

.include "../../mk/bsd.pkg.mk"
