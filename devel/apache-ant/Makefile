# $NetBSD: Makefile,v 1.5 2003/11/22 23:55:15 jlam Exp $
#
# NOTE: if you are depending on ant from another package, please be aware that
# the ant team has CHANGED the version numbering scheme.  A previous version
# of ant was 3.1.  Do NOT use dependency patterns such as >=1.3 which could pick
# up this version by mistake.

DISTNAME=	${PKGNAME}-src
PKGNAME=	apache-ant-1.5.4
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=ant/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://ant.apache.org/
COMMENT=	"Apache Project's Java-Based make(1) replacement"

DEPENDS+=	crimson>=1.1.3:../../textproc/crimson

# Up to version 1.5.1 inclusive this was known as "jakarta-ant".
CONFLICTS=	jakarta-ant*

USE_BUILDLINK2=	# defined

EXTRACT_CMD_OPTS.zip=	-Caq

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD} cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} ${SH} bootstrap.sh

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'			\
		< ${FILESDIR}/ant > ${WRKDIR}/ant

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ant ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/antRun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/build/lib/ant.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/ant
	cd ${WRKSRC}/docs && ${PAX} -rw -pp * ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/java/ant

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

CLASSPATH:=	${CLASSPATH}:${LOCALBASE}/lib/java/crimson.jar
