# $NetBSD: Makefile,v 1.18 2005/09/03 22:59:25 tonio Exp $
#
# NOTE: if you are depending on ant from another package, please be aware that
# the ant team has CHANGED the version numbering scheme.  A previous version
# of ant was 3.1.  Do NOT use dependency patterns such as >=1.3 which could pick
# up this version by mistake.

DISTNAME=	apache-ant-1.6.5
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=ant/binaries/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://ant.apache.org/
COMMENT=	"Apache Project's Java-Based make(1) replacement"

DEPENDS+=	crimson>=1.1.3:../../textproc/crimson

# Up to version 1.5.1 inclusive this was known as "jakarta-ant".
CONFLICTS=	jakarta-ant*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_JAVA=	run
USE_JAVA2=	yes
NO_BUILD=	yes

SUBST_CLASSES+=  ant
SUBST_FILES.ant= bin/ant
SUBST_STAGE.ant= pre-configure
SUBST_SED.ant=-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g' -e 's,@PREFIX@,${PREFIX},g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ant ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/ant.jar ${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/ant-*.jar ${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/xercesImpl.jar ${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/xml-apis.jar ${PREFIX}/lib/java/ant
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/ant
	cd ${WRKSRC}/docs && ${PAX} -rw -pmp * ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/java/ant

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
