# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:32 wiz Exp $

DISTNAME=	jakarta-ant
PKGNAME=	jakarta-ant-3.1
CATEGORIES=	devel
MASTER_SITES=	http://jakarta.apache.org/builds/ant/release/v3.1/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache Project's Java-Based make(1) replacement

DIST_SUBDIR=	jakarta-3.1
USE_JAVA=	yes

WRKSRC=		${WRKDIR}/jakarta-ant

do-build:
	cd ${WRKSRC} && ${SH} bootstrap.sh

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' -e 's,@JAVA_HOME@,${JAVA_HOME},g' \
		< ${WRKSRC}/bin/ant > ${WRKSRC}/bin/ant.tmp
	${MV} ${WRKSRC}/bin/ant.tmp ${WRKSRC}/bin/ant

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ant ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/antRun ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/xml.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/ant.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/docs/index.html ${PREFIX}/share/doc/java/ant

.include "../../mk/bsd.pkg.mk"
