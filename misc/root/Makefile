# $NetBSD: Makefile,v 1.14 2004/01/20 12:21:02 agc Exp $

DISTNAME=		root_v2.23.08.source
PKGNAME=		root-2.23
CATEGORIES=		misc
MASTER_SITES=		ftp://root.cern.ch/root/

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://root.cern.ch/
COMMENT=		OO framework for data analysis and visualisation

BUILD_DEPENDS+=		cint-5.14.40:../../lang/cint

WRKSRC=			${WRKDIR}
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES

ALL_TARGET=		netbsd
MAKE_ENV=		LD_LIBRARY_PATH=${WRKDIR}/lib ROOTSYS=${WRKDIR}

.if (${MACHINE_ARCH} == "arm")
BROKEN= 	Compilation stops due to internal compiler error
.endif

do-configure:
	${CP} ${FILESDIR}/Makefile.netbsd ${WRKDIR}/src
	${MKDIR} ${WRKDIR}/bin
	${MKDIR} ${WRKDIR}/lib
	${CP} ${PREFIX}/cint/MAKEINFO ${WRKDIR}/cint
	${CP} ${PREFIX}/cint/include/iosenum.h ${WRKDIR}/cint/include

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/root
	${INSTALL_DATA_DIR} ${PREFIX}/root/include
	(cd ${WRKDIR}/src; ${CP} *.h MAIN_rmain.cxx ${PREFIX}/root/include)
	(cd ${WRKDIR}; tar cf - lib bin cint)|(cd ${PREFIX}/root;tar xf -)
	${SED} "s;XXXPREFIXXXX;${PREFIX};g" <${FILESDIR}/root.sh >${PREFIX}/bin/root
	${CHMOD} +x ${PREFIX}/bin/root

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
