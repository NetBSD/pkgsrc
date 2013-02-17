# $NetBSD: Makefile,v 1.6 2013/02/17 17:37:41 fhajny Exp $
#

DISTNAME=	apache-maven-3.0.4
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=maven/maven-3/${PKGVERSION_NOREV}/binaries/}
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	yyamano@NetBSD.org
HOMEPAGE=	http://maven.apache.org/
COMMENT=	Apache Project's software project management and comprehension tool
LICENSE=	apache-2.0

USE_JAVA=	run
USE_JAVA2=	1.5
USE_TOOLS+=	pax
NO_BUILD=	yes

SUBST_CLASSES+=		maven
SUBST_FILES.maven=	bin/mvn
SUBST_STAGE.maven=	pre-configure
SUBST_SED.maven=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.maven+=	-e 's,@PREFIX@,${PREFIX},g'

INSTALLATION_DIRS=	bin etc/maven lib/java/maven lib/java/maven/boot
INSTALLATION_DIRS+=	share/doc/java/maven share/examples/maven

CONF_FILES+=	share/examples/maven/m2.conf ${PKG_SYSCONFDIR}/m2.conf
CONF_FILES+=	share/examples/maven/settings.xml ${PKG_SYSCONFDIR}/settings.xml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mvn ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/m2.conf ${DESTDIR}${PREFIX}/share/examples/maven
	${INSTALL_DATA} ${WRKSRC}/conf/settings.xml ${DESTDIR}${PREFIX}/share/examples/maven
	${INSTALL_DATA} ${WRKSRC}/boot/*.jar ${DESTDIR}${PREFIX}/lib/java/maven/boot
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DESTDIR}${PREFIX}/lib/java/maven
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/java/maven
	${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${DESTDIR}${PREFIX}/share/doc/java/maven
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DESTDIR}${PREFIX}/share/doc/java/maven

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
