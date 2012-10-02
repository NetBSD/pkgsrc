# $NetBSD: Makefile,v 1.18 2012/10/02 20:11:43 asau Exp $
#

DISTNAME=	joos-0.2
PKGREVISION=	1
CATEGORIES=	lang java
MASTER_SITES=	# ftp://netbsd.stevens-tech.edu/pub/NetBSD/packages/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brics.dk/~mis/dOvs/index.html
COMMENT=	Java Object Oriented Subset

MAKE_JOBS_SAFE=		no

USE_JAVA=	run
USE_TOOLS+=	pax yacc flex csh:run

REPLACE_CSH+=	Bin/dejava
REPLACE_CSH+=	Bin/jappletviewer
REPLACE_CSH+=	Bin/jasmin
REPLACE_CSH+=	Bin/jjasmin
REPLACE_CSH+=	Bin/jjava
REPLACE_CSH+=	Bin/jjavac
REPLACE_CSH+=	Bin/jjavap
REPLACE_CSH+=	Bin/joosc

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/joos
	cd ${WRKSRC} && pax -s ,^./.*orig,, -rw . ${DESTDIR}${PREFIX}/joos
	cd ${DESTDIR}${PREFIX}/joos/Bin && ${LN} -s joos.a- joos

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
