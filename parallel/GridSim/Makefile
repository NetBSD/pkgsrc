# $NetBSD: Makefile,v 1.1.1.1 2003/07/03 16:44:50 jschauma Exp $
#

DISTNAME=		gridsimtoolkit-2.1
PKGNAME=		GridSim-2.1
CATEGORIES=		parallel devel
MASTER_SITES=		http://www.cs.mu.oz.au/~raj/grids/gridsim/gridsim2.1/

MAINTAINER=		jschauma@netbsd.org
HOMEPAGE=		http://www.gridbus.org/gridsim/
COMMENT=		toolkit for simulation of parallel systems

USE_JAVA2=		run
PKG_JVMS_ACCEPTED=	sun-jdk14
NO_BUILD=		# defined

do-configure:
	${CHMOD} -R a+rX ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/GridSim
	cd ${WRKSRC} && ${PAX} -rw classes jars source ${PREFIX}/GridSim/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/GridSim
	cd ${WRKSRC}/doc && ${PAX} -rw . ${PREFIX}/share/doc/html/GridSim
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/GridSim
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/GridSim

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
