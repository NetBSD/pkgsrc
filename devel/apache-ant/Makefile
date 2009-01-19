# $NetBSD: Makefile,v 1.26 2009/01/19 00:38:17 christos Exp $
#

DISTNAME=	apache-ant-1.7.1
#PKGREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=ant/binaries/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://ant.apache.org/
COMMENT=	Apache Project's Java-Based make(1) replacement

# Up to version 1.5.1 inclusive this was known as "jakarta-ant".
CONFLICTS=	jakarta-ant>=0

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA} ${WRKSRC}/lib/xercesImpl.jar ${DESTDIR}${PREFIX}/lib/java/ant
	${INSTALL_DATA} ${WRKSRC}/lib/xml-apis.jar ${DESTDIR}${PREFIX}/lib/java/ant
	cd ${WRKSRC}/docs && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DESTDIR}${PREFIX}/share/doc/java/ant

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
