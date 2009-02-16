# $NetBSD: Makefile,v 1.13 2009/02/16 13:34:38 joerg Exp $
#

DISTNAME=		gridsimtoolkit-3.0
PKGNAME=		GridSim-3.0.2
PKGREVISION=		2
CATEGORIES=		parallel devel java
MASTER_SITES=		http://www.gridbus.org/gridsim/download/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-patch2${EXTRACT_SUFX}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gridbus.org/gridsim/
COMMENT=		Toolkit for simulation of parallel systems

USE_TOOLS+=	pax
USE_JAVA2=		1.4
PKG_JVMS_ACCEPTED=	sun-jdk14 jdk14
NO_BUILD=		yes

do-configure:
	${CHMOD} -R a+rX ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/GridSim
	cd ${WRKSRC} && pax -rw application jars source ${PREFIX}/GridSim/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/GridSim
	cd ${WRKSRC}/doc && pax -rw . ${PREFIX}/share/doc/html/GridSim
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/GridSim
.for f in bugfix changelog faq readme
	${INSTALL_DATA} ${WRKSRC}/${f}.txt ${PREFIX}/share/doc/GridSim/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/GridSim
	cd ${WRKSRC}/examples && pax -rw . ${PREFIX}/share/examples/GridSim
	cd ${WRKSRC}-patch2/doc && pax -rw . ${PREFIX}/share/doc/html/GridSim
	cd ${WRKSRC}-patch2/jars && pax -rw . ${PREFIX}/GridSim/jars/
	cd ${WRKSRC}-patch2/source && pax -rw . ${PREFIX}/GridSim/source/
	${INSTALL_DATA} ${WRKSRC}-patch2/readme_v3.0-patch2.txt ${PREFIX}/share/doc/GridSim/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
