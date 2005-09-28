# $NetBSD: Makefile,v 1.7 2005/09/28 20:52:25 rillig Exp $
#

DISTNAME=		gridsimtoolkit-3.0
PKGNAME=		GridSim-3.0.2
CATEGORIES=		parallel devel java
MASTER_SITES=		http://www.gridbus.org/gridsim/download/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-patch2${EXTRACT_SUFX}
EXTRACT_SUFX=		.zip

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.gridbus.org/gridsim/
COMMENT=		Toolkit for simulation of parallel systems

USE_JAVA2=		run
PKG_JVMS_ACCEPTED=	sun-jdk14 jdk14
NO_BUILD=		yes

do-configure:
	${CHMOD} -R a+rX ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/GridSim
	cd ${WRKSRC} && ${PAX} -rw application jars source ${PREFIX}/GridSim/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/GridSim
	cd ${WRKSRC}/doc && ${PAX} -rw . ${PREFIX}/share/doc/html/GridSim
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/GridSim
.for f in bugfix changelog faq readme
	${INSTALL_DATA} ${WRKSRC}/${f}.txt ${PREFIX}/share/doc/GridSim/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/GridSim
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/GridSim
	cd ${WRKSRC}-patch2/doc && ${PAX} -rw . ${PREFIX}/share/doc/html/GridSim
	cd ${WRKSRC}-patch2/jars && ${PAX} -rw . ${PREFIX}/GridSim/jars/
	cd ${WRKSRC}-patch2/source && ${PAX} -rw . ${PREFIX}/GridSim/source/
	${INSTALL_DATA} ${WRKSRC}-patch2/readme_v3.0-patch2.txt ${PREFIX}/share/doc/GridSim/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
