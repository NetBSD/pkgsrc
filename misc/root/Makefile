# $NetBSD: Makefile,v 1.6 2001/02/25 04:18:02 hubertf Exp $

DISTNAME=		root_v2.23.08.source
PKGNAME=		root-2.23
NO_WRKSUBDIR=		yes
CATEGORIES=		misc
MASTER_SITES=		ftp://root.cern.ch/root/

MAINTAINER=		drochner@netbsd.org
HOMEPAGE=		http://root.cern.ch/
COMMENT=		OO framework for data analysis and visualisation

BUILD_DEPENDS+=		cint:../../lang/cint

USE_GMAKE=		YES
USE_XPM=		YES

ALL_TARGET=		netbsd
MAKE_ENV=		LD_LIBRARY_PATH=${WRKDIR}/lib ROOTSYS=${WRKDIR}

do-configure:
	${CP} ${FILESDIR}/Makefile.netbsd ${WRKDIR}/src
	${INSTALL_PROGRAM_DIR} ${WRKDIR}/bin
	${INSTALL_DATA_DIR} ${WRKDIR}/lib
	${INSTALL_DATA} ${PREFIX}/cint/MAKEINFO ${WRKDIR}/cint
	${INSTALL_DATA} ${PREFIX}/cint/include/iosenum.h ${WRKDIR}/cint/include

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/root
	${INSTALL_DATA_DIR} ${PREFIX}/root/include
	(cd ${WRKDIR}/src; ${CP} *.h MAIN_rmain.cxx ${PREFIX}/root/include)
	(cd ${WRKDIR}; tar cf - lib bin cint)|(cd ${PREFIX}/root;tar xf -)
	${SED} "s;XXXPREFIXXXX;${PREFIX};g" <${FILESDIR}/root.sh >${PREFIX}/bin/root
	${CHMOD} +x ${PREFIX}/bin/root

.include "../../mk/bsd.pkg.mk"
