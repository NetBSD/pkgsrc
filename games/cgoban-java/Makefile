# $NetBSD: Makefile,v 1.21 2004/09/24 10:58:18 rh Exp $
#

DISTNAME=	cgoban-unix-2.6.5
PKGNAME=	${DISTNAME:S/unix/java/}
CATEGORIES=	games java
MASTER_SITES=	http://kgs.kiseido.com/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://kgs.kiseido.com/en_US/download.html
COMMENT=	Java Go server client and SGF viewer/editor

WRKSRC=		${WRKDIR}/cgoban
NO_BUILD=	yes
USE_BUILDLINK3=	yes
USE_JAVA2=	yes
USE_JAVA=	run

do-configure:
	${SED}	-e 's|\(_DIR=\).|\1${PREFIX}/libexec|'			\
		-e 's|^\(java\)|${PKG_JAVA_HOME}/bin/\1|'		\
		< ${WRKSRC}/cgoban.sh.in > ${WRKSRC}/cgoban.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban.sh ${PREFIX}/bin/cgoban-java
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${PREFIX}/libexec

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
