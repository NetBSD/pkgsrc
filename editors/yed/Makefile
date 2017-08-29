# $NetBSD: Makefile,v 1.8 2017/08/29 08:40:31 wiz Exp $

DISTNAME=	yEd-3.17
PKGNAME=	${DISTNAME:S/yEd/yed/}
CATEGORIES=	editors
MASTER_SITES=	https://www.yworks.com/resources/yed/demo/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yworks.com/en/
COMMENT=	Graph editor (UML, Flowcharts, BPMN and more)
LICENSE=	yed-license

RESTRICTED=		Redistribution prohibited
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_JAVA=	run
USE_JAVA2=	6

YEDDIR=		${PREFIX}/lib/java/yed

INSTALLATION_DIRS=	bin lib/java/yed/lib lib/java/yed/icons share/doc/java/yed

do-build:
	${SED} -e "s,@YEDDIR@,${YEDDIR}," ${FILESDIR}/yed.sh > ${WRKSRC}/yed

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yed ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yed.jar ${DESTDIR}${PREFIX}/lib/java/yed
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib/java/yed/lib
	${INSTALL_DATA} ${WRKSRC}/icons/* ${DESTDIR}${PREFIX}/lib/java/yed/icons

	${INSTALL_DATA} ${WRKSRC}/license.html ${DESTDIR}${PREFIX}/share/doc/java/yed

.include "../../mk/bsd.pkg.mk"
