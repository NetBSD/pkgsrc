# $NetBSD: Makefile,v 1.3 2002/10/04 16:39:40 jschauma Exp $
#

DISTNAME=	joos-0.2
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
	cd ${WRKSRC} && ${PAX} -s ,^./.*orig,, -rw . ${PREFIX}/joos
	cd ${PREFIX}/joos/Bin && ${LN} -s joos.a- joos

.include "../../mk/bsd.pkg.mk"
