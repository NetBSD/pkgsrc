# $NetBSD: Makefile,v 1.6 2020/05/17 00:54:00 tnn Exp $
#

DISTNAME=	apache-ivy-2.4.0-bin
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=ant/ivy/${PKGNAME:S/apache-ivy-//}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ant.apache.org/ivy/
COMMENT=	"Apache Project's Java-Based agile dependency manager"
LICENSE=	apache-2.0

.include "../../mk/java-vm.mk"

.if ${PKG_JVM} == "sun-jdk7"
DEPENDS+=	apache-ant>=1.9<1.10:../../devel/apache-ant19
.else
DEPENDS+=	apache-ant>=1.10:../../devel/apache-ant
.endif

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java/ant share/doc/java/ivy share/examples/ivy

do-install:
	${INSTALL_DATA} ${WRKSRC}/ivy-*.jar ${DESTDIR}${PREFIX}/lib/java/ant

	cd ${WRKSRC}/doc && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/doc/java/ivy
	cd ${WRKSRC}/src/example && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/examples/ivy

.include "../../mk/bsd.pkg.mk"
