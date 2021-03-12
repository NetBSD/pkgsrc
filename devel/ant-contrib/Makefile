# $NetBSD: Makefile,v 1.4 2021/03/12 17:49:11 ryoon Exp $

DISTNAME=	ant-contrib-1.0b3-bin
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ant-contrib/ant-contrib/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ant-contrib.sourceforge.net/
COMMENT=	Collection of tasks and tools for apache-ant
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${PKGBASE}

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java/ant share/doc/java/ant-contrib

DEPENDS+=	apache-ant>=1.5:../../devel/apache-ant

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PKGNAME_NOREV}.jar ${DESTDIR}${PREFIX}/lib/java/ant
	cd ${WRKSRC}/docs && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/doc/java/ant-contrib

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
