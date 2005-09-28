# $NetBSD: Makefile,v 1.19 2005/09/28 20:52:23 rillig Exp $
#

DISTNAME=	jasmin-1.06
CATEGORIES=     lang java
MASTER_SITES=	http://www.cat.nyu.edu/~meyer/jasmin/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.cat.nyu.edu/~meyer/jasmin/
COMMENT=	Java "assembler" interface

USE_JAVA=	run

WRKSRC=		${WRKDIR}/jasmin
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

post-patch:
	${MV} ${WRKSRC}/bin/jasmin ${WRKSRC}/bin/jasmin.patch && 	\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' 			\
		${WRKSRC}/bin/jasmin.patch > ${WRKSRC}/bin/jasmin && 	\
		${CHMOD} 755 ${WRKSRC}/bin/jasmin
	${CHMOD} -R ugo+rX ${WRKSRC}/
	${RM} ${WRKSRC}/bin/jasmin.patch

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/jasmin
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}/jasmin
	${LN} -s ${PREFIX}/jasmin/bin/jasmin ${PREFIX}/bin/jasmin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
