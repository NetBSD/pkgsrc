# $NetBSD: Makefile,v 1.3 2020/01/26 05:26:22 rillig Exp $

DISTNAME=	ant-contrib-0.6-bin
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ant-contrib/ant-contrib/${PKGNAME_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ant-contrib.sourceforge.net/
COMMENT=	Collection of tasks and tools for apache-ant
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java/ant share/doc/java/ant-contrib

DEPENDS+=	apache-ant>=1.5:../../devel/apache-ant

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PKGNAME_NOREV}.jar ${DESTDIR}${PREFIX}/lib/java/ant
	cd ${WRKSRC}/docs && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/doc/java/ant-contrib
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/java/ant-contrib

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
