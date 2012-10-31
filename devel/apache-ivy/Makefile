# $NetBSD: Makefile,v 1.2 2012/10/31 11:16:34 asau Exp $
#

DISTNAME=	apache-ivy-2.2.0-bin
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=ant/ivy/${PKGNAME:S/apache-ivy-//}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ant.apache.org/ivy/
COMMENT=	"Apache Project's Java-Based agile dependency manager"
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
DEPENDS+=	apache-ant>=1.6:../../devel/apache-ant

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java/ant share/doc/java/ivy share/examples/ivy

do-install:
	${INSTALL_DATA} ${WRKSRC}/ivy-*.jar ${DESTDIR}${PREFIX}/lib/java/ant

	cd ${WRKSRC}/doc && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/doc/java/ivy
	cd ${WRKSRC}/src/example && pax -rw -pmp * ${DESTDIR}${PREFIX}/share/examples/ivy

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
