# $NetBSD: Makefile,v 1.35 2014/05/02 12:16:38 wiz Exp $

DISTNAME=	apache-ant-1.9.3-bin
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=ant/binaries/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://ant.apache.org/
COMMENT=	"Apache Project's Java-Based make(1) replacement"
LICENSE=	apache-2.0

# Up to version 1.5.1 inclusive this was known as "jakarta-ant".
CONFLICTS=	jakarta-ant>=0

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_BUILD=	yes

SUBST_CLASSES+=		ant
SUBST_FILES.ant=	bin/ant
SUBST_STAGE.ant=	pre-configure
SUBST_SED.ant=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.ant+=		-e 's,@PREFIX@,${PREFIX},g'

INSTALLATION_DIRS=	bin lib/java/ant share/doc/java/ant

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ant ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/ant.jar ${DESTDIR}${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/ant-*.jar ${DESTDIR}${PREFIX}/lib/java/ant
	cd ${WRKSRC}/manual && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DESTDIR}${PREFIX}/share/doc/java/ant

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
