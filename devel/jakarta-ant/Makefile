# $NetBSD: Makefile,v 1.10 2002/04/13 21:12:15 jwise Exp $
#
# NOTE: if you are depending on ant from another package, please be aware that
# the ant team has CHANGED the version numbering scheme.  A previous version
# of ant was 3.1.  Do NOT use dependency patterns such as >=1.3 which could pick
# up this version by mistake.

DISTNAME=	${PKGNAME}-src
PKGNAME=	jakarta-ant-1.4.1
CATEGORIES=	devel
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-ant/release/v1.4.1/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	Apache Project's Java-Based make(1) replacement

USE_JAVA=	yes
DEPENDS+=	crimson>=1.1.3:../../textproc/crimson

WRKSRC=		${WRKDIR}/${PKGNAME}

post-extract:
	@${RM} ${WRKSRC}/lib/*.jar

do-build:
	${_PKG_SILENT}${_PKG_DEBUG} cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} ${SH} bootstrap.sh

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' -e 's,@JAVA_HOME@,${JAVA_HOME},g' \
		< ${FILESDIR}/ant > ${WRKDIR}/ant

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ant ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/antRun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/build/lib/ant.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/ant
	cd ${WRKSRC}/docs && ${PAX} -rwpp * ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/java/ant

.include "../../mk/bsd.pkg.mk"
CLASSPATH:=	${CLASSPATH}:${LOCALBASE}/lib/java/crimson.jar
