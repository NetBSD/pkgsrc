# $NetBSD: Makefile,v 1.5 2008/04/20 16:08:20 adrianp Exp $
#

DISTNAME=	opengrok-0.6.1
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

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/opengrok/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/opengrok

	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/opengrok.jar \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/source.war \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${DESTDIR}${PREFIX}/share/opengrok/lib
	${INSTALL_DATA} ${WRKSRC}/paths.tsv \
		${DESTDIR}${PREFIX}/share/examples/opengrok
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_SCRIPT} ${WRKSRC}/run-quiet.sh \
		${DESTDIR}${PREFIX}/share/opengrok

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
