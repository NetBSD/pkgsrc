# $NetBSD: Makefile,v 1.2 2002/08/07 20:16:42 jschauma Exp $
#

DISTNAME=	joos-0.1
CATEGORIES=     lang
MASTER_SITES=	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.brics.dk/~mis/dOvs/index.html
COMMENT=	Java Object Oriented Subset

USE_JAVA=	run
PKG_JVM=	sun-jdk

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/joos
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}/joos

.include "../../mk/bsd.pkg.mk"
