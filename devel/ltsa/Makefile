# $NetBSD: Makefile,v 1.3 2006/01/20 16:15:53 jmmv Exp $
#

DISTNAME=	ltsa2.2
PKGNAME=	${DISTNAME:S/ltsa/ltsa-/}
CATEGORIES=	devel
MASTER_SITES=	http://www.doc.ic.ac.uk/~jnm/book/ltsa-v2/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.doc.ic.ac.uk/~jnm/book/ltsa-v2/
COMMENT=	Labelled Transition System Analyser

NO_CONFIGURE=		YES
USE_JAVA2=		YES

INSTALLATION_DIRS=	bin

do-build:
	@${ECHO} "Generating ltsa.sh script..."
	@${ECHO} '#!${SH}' >${WRKSRC}/ltsa.sh
	@${ECHO} '${ULIMIT_CMD_datasize}' >>${WRKSRC}/ltsa.sh
	@${ECHO} '${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/ltsa/ltsa.jar' \
		'$$*' >>${WRKSRC}/ltsa.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ltsa.sh ${PREFIX}/bin/ltsa
	${INSTALL_DATA_DIR} ${PREFIX}/lib/ltsa
	cd ${WRKSRC}/lib && ${PAX} -rwpppm . ${PREFIX}/lib/ltsa
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ltsa
	${INSTALL_DATA} ${WRKSRC}/fspv2.pdf ${PREFIX}/share/doc/ltsa
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/ltsa
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ltsa
	cd ${WRKSRC}/examples && ${PAX} -rwpppm . ${PREFIX}/share/examples/ltsa

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
