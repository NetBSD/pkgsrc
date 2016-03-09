# $NetBSD: Makefile,v 1.2 2016/03/09 20:43:38 tnn Exp $

DISTNAME=	yEd-3.15
PKGNAME=	${DISTNAME:C:E:e:}
CATEGORIES=	editors
MASTER_SITES=	http://www.yworks.com/products/yed/demo/
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

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S:E:e:}

USE_JAVA=	run
USE_JAVA2=	6

YEDDIR=		${PREFIX}/lib/java/yed

INSTALLATION_DIRS=bin lib/java/yed/lib lib/java/yed/icons share/doc/java/yed

do-build:
	${SED} -e "s,@YEDDIR@,${YEDDIR}," ${FILESDIR}/yed.sh > ${WRKSRC}/yed

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yed ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/yed.jar ${DESTDIR}${PREFIX}/lib/java/yed
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib/java/yed/lib
	${INSTALL_DATA} ${WRKSRC}/icons/* ${DESTDIR}${PREFIX}/lib/java/yed/icons

	${INSTALL_DATA} ${WRKSRC}/license.html ${DESTDIR}${PREFIX}/share/doc/java/yed

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
