# $NetBSD: Makefile,v 1.17 2005/06/16 06:57:45 jlam Exp $
#
# NOTE: if you are depending on ant from another package, please be aware that
# the ant team has CHANGED the version numbering scheme.  A previous version
# of ant was 3.1.  Do NOT use dependency patterns such as >=1.3 which could pick
# up this version by mistake.

DISTNAME=	apache-ant-1.6.2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=ant/binaries/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ant.apache.org/
COMMENT=	"Apache Project's Java-Based make(1) replacement"

DEPENDS+=	crimson>=1.1.3:../../textproc/crimson

# Up to version 1.5.1 inclusive this was known as "jakarta-ant".
CONFLICTS=	jakarta-ant*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_JAVA=	run
USE_JAVA2=	yes

EXTRACT_CMD_OPTS.zip=	-Caq
INSTALLATION_DIRS=	bin

do-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'			\
		< ${FILESDIR}/ant > ${WRKDIR}/ant

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ant ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/ant.jar ${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/ant-nodeps.jar ${PREFIX}/lib/java/ant
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/ant
	cd ${WRKSRC}/docs && ${PAX} -rw -pmp * ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/java/ant

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
