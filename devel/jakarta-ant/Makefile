# $NetBSD: Makefile,v 1.5 2001/03/18 22:53:47 jwise Exp $

DISTNAME=	${PKGNAME}-src
PKGNAME=	jakarta-ant-1.3
CATEGORIES=	devel
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-ant/release/v1.3/src/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://jakarta.apache.org/
COMMENT=	the Apache Project's Java-Based make(1) replacement

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}

do-build:
	cd ${WRKSRC} && ${SH} bootstrap.sh

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' -e 's,@JAVA_HOME@,${JAVA_HOME},g' \
		< ${FILESDIR}/ant > ${WRKDIR}/ant

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ant ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/antRun ${PREFIX}/bin
	-${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/jaxp.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/parser.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/build/lib/ant.jar ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/build/lib/optional.jar ${PREFIX}/lib/java/ant-optional.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/ant/manual
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/java/ant
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/java/ant
	(cd ${WRKSRC}/docs/manual && ${GTAR} pcf - .) | \
		(cd ${PREFIX}/share/doc/java/ant/manual && ${GTAR} pxvf -)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/ant

.include "../../mk/bsd.pkg.mk"
