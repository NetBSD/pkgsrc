# $NetBSD: Makefile,v 1.1.1.1 2002/12/07 00:27:03 rh Exp $
#

DISTNAME=	cgoban-unix-2.4.55
PKGNAME=	${DISTNAME:S/unix/java/}
WRKSRC=		${WRKDIR}/cgoban
CATEGORIES=	games
MASTER_SITES=	http://kgs.kiseido.com/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://kgs.kiseido.com/en_US/download.html
COMMENT=	Java Go server client and sgf viewer/editor

NO_BUILD=	YES
USE_BUILDLINK2=	YES
USE_JAVA=	run

do-configure:
	${SED}	-e 's|\(_DIR=\).|\1${PREFIX}/libexec|'			\
		-e 's|^\(java\)|${PKG_JAVA_HOME}/bin/\1|'		\
		< ${WRKSRC}/cgoban.sh.in > ${WRKSRC}/cgoban.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban.sh ${PREFIX}/bin/cgoban-java
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
