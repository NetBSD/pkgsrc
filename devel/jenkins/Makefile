# $NetBSD: Makefile,v 1.18 2015/12/17 20:20:30 asau Exp $
#

DISTNAME=	jenkins
PKGNAME=	jenkins-${J_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://mirrors.jenkins-ci.org/war/${J_VERSION}/
EXTRACT_SUFX=	.war

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://jenkins-ci.org/
COMMENT=	Open source continuous integration server (LTS release)
LICENSE=	mit

J_VERSION=	1.642

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

USE_JAVA=	run
USE_JAVA2=	7

USE_TOOLS+=	unzip

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/jenkins

do-install:
	${UNZIP_CMD} -d ${DESTDIR}${PREFIX}/share/jenkins ${WRKSRC}/jenkins.war
	${INSTALL_DATA} ${WRKSRC}/jenkins.war ${DESTDIR}${PREFIX}/share/jenkins

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
