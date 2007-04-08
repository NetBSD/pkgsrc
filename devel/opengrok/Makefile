# $NetBSD: Makefile,v 1.1.1.1 2007/04/08 16:59:41 adrianp Exp $
#

DISTNAME=	opengrok-0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.opensolaris.org/os/project/opengrok/files/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.opensolaris.org/os/project/opengrok/files/
COMMENT=	Fast and usable source code search and cross reference engine

DEPENDS+=	exctags-[0-9]*:../../devel/exctags
DEPENDS+=	apache-tomcat>=5.5:../../www/apache-tomcat55
DEPENDS+=	jflex-[0-9]*:../../devel/jflex
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	zip-[0-9]*:../../archivers/zip

NO_BUILD=	YES
USE_JAVA=	run
USE_JAVA2=	1.5

CONF_FILES=	${PREFIX}/share/examples/opengrok/paths.tsv \
		${PREFIX}/share/opengrok/paths.tsv

SUBST_CLASSES+=		run
SUBST_STAGE.run=	post-patch
SUBST_FILES.run=	run.sh run-quiet.sh
SUBST_SED.run=		-e "s|/usr/local/bin/ctags|${PREFIX}/bin/exctags|g"
SUBST_SED.run+=		-e "s|java|${PKG_JAVA_HOME}/bin/java|g"
SUBST_SED.run+=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.run=	Fixing hardcoded paths.

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/opengrok
	${INSTALL_DATA_DIR} ${PREFIX}/share/opengrok/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/opengrok
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/opengrok/conf

	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/opengrok.jar ${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/source.war ${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${PREFIX}/share/opengrok/lib
	${INSTALL_DATA} ${WRKSRC}/paths.tsv ${PREFIX}/share/examples/opengrok
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh ${PREFIX}/share/opengrok
	${INSTALL_SCRIPT} ${WRKSRC}/run-quiet.sh ${PREFIX}/share/opengrok

	cd ${WRKSRC}/conf && ${PAX} -rw . ${PREFIX}/share/examples/opengrok/conf

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
