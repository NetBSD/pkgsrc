# $NetBSD: Makefile,v 1.5 2001/02/17 18:09:21 wiz Exp $

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
	${MKDIR} ${WRKDIR}/bin
	${MKDIR} ${WRKDIR}/lib
	${CP} ${PREFIX}/cint/MAKEINFO ${WRKDIR}/cint
	${CP} ${PREFIX}/cint/include/iosenum.h ${WRKDIR}/cint/include

do-install:
	${MKDIR} ${PREFIX}/root
	${MKDIR} ${PREFIX}/root/include
	(cd ${WRKDIR}/src; ${CP} *.h MAIN_rmain.cxx ${PREFIX}/root/include)
	(cd ${WRKDIR}; tar cf - lib bin cint)|(cd ${PREFIX}/root;tar xf -)
	${SED} "s;XXXPREFIXXXX;${PREFIX};g" <${FILESDIR}/root.sh >${PREFIX}/bin/root
	${CHMOD} +x ${PREFIX}/bin/root

.include "../../mk/bsd.pkg.mk"
