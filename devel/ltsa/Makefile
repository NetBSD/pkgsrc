# $NetBSD: Makefile,v 1.7 2008/03/03 17:45:36 jlam Exp $
#

DISTNAME=	ltsa2.2
PKGNAME=	${DISTNAME:S/ltsa/ltsa-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.doc.ic.ac.uk/~jnm/book/ltsa-v2/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.doc.ic.ac.uk/~jnm/book/ltsa-v2/
# ~jnm exists, /book/ does not
COMMENT=	Labelled Transition System Analyser

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_SCRIPT} ${WRKSRC}/ltsa.sh ${DESTDIR}${PREFIX}/bin/ltsa
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ltsa
	cd ${WRKSRC}/lib && ${PAX} -rwpppm . ${DESTDIR}${PREFIX}/lib/ltsa
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ltsa
	${INSTALL_DATA} ${WRKSRC}/fspv2.pdf ${DESTDIR}${PREFIX}/share/doc/ltsa
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/ltsa
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/ltsa
	cd ${WRKSRC}/examples && ${PAX} -rwpppm . ${DESTDIR}${PREFIX}/share/examples/ltsa

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
