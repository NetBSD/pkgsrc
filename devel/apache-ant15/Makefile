# $NetBSD: Makefile,v 1.12 2012/10/31 11:16:34 asau Exp $
#
# NOTE: if you are depending on ant from another package, please be aware that
# the ant team has CHANGED the version numbering scheme.  A previous version
# of ant was 3.1.  Do NOT use dependency patterns such as >=1.3 which could pick
# up this version by mistake.

DISTNAME=	apache-ant-1.5.4
PKGREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://archive.apache.org/dist/ant/binaries/
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ant.apache.org/
COMMENT=	"Apache Project's Java-Based make(1) replacement"

DEPENDS+=	crimson>=1.1.3:../../textproc/crimson

# Up to version 1.5.1 inclusive this was known as "jakarta-ant".
CONFLICTS=	jakarta-ant*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_JAVA=	run
USE_TOOLS+=	pax

EXTRACT_OPTS_ZIP=	-Caq
INSTALLATION_DIRS=	bin

do-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'			\
		< ${FILESDIR}/ant > ${WRKDIR}/ant

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ant ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/ant.jar ${DESTDIR}${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/optional.jar ${DESTDIR}${PREFIX}/lib/java/ant
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java/ant
	cd ${WRKSRC}/docs && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DESTDIR}${PREFIX}/share/doc/java/ant

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
