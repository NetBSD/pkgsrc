# $NetBSD: Makefile,v 1.6 2003/07/17 21:44:45 grant Exp $
#

DISTNAME=	joos-0.2
CATEGORIES=     lang
MASTER_SITES=	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.brics.dk/~mis/dOvs/index.html
COMMENT=	Java Object Oriented Subset

USE_JAVA=	run

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/joos
	cd ${WRKSRC} && ${PAX} -s ,^./.*orig,, -rw . ${PREFIX}/joos
	cd ${PREFIX}/joos/Bin && ${LN} -s joos.a- joos

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
