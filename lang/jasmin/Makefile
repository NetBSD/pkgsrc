# $NetBSD: Makefile,v 1.29 2012/10/02 20:11:43 asau Exp $
#

DISTNAME=	jasmin-1.06
PKGREVISION=	2
CATEGORIES=	lang java
MASTER_SITES=	http://mrl.nyu.edu/~meyer/jasmin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mrl.nyu.edu/~meyer/jasmin/
COMMENT=	Java "assembler" interface

USE_JAVA=	run
USE_TOOLS+=	pax csh:run

WRKSRC=		${WRKDIR}/jasmin
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

REPLACE_CSH+=	bin/jasmin bin/jasmin.orig bin/runall.sh lib/cup/INSTALL

post-patch:
	${MV} ${WRKSRC}/bin/jasmin ${WRKSRC}/bin/jasmin.patch && 	\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' 			\
		${WRKSRC}/bin/jasmin.patch > ${WRKSRC}/bin/jasmin && 	\
		${CHMOD} 755 ${WRKSRC}/bin/jasmin
	${CHMOD} -R u=rwX,go=rX ${WRKSRC}/
	${RM} ${WRKSRC}/bin/jasmin.patch

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/jasmin
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/jasmin
	${LN} -s ../jasmin/bin/jasmin ${DESTDIR}${PREFIX}/bin/jasmin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
