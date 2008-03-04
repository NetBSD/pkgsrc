# $NetBSD: Makefile,v 1.10 2008/03/04 16:38:12 jlam Exp $
#

DISTNAME=	joos-0.2
CATEGORIES=	lang java
MASTER_SITES=	ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.brics.dk/~mis/dOvs/index.html
COMMENT=	Java Object Oriented Subset

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=	run

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/joos
	cd ${WRKSRC} && ${PAX} -s ,^./.*orig,, -rw . ${DESTDIR}${PREFIX}/joos
	cd ${DESTDIR}${PREFIX}/joos/Bin && ${LN} -s joos.a- joos

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
