# $NetBSD: Makefile,v 1.25 2008/05/26 02:13:21 joerg Exp $
#

DISTNAME=	jasmin-1.06
PKGREVISION=	1
CATEGORIES=	lang java
MASTER_SITES=	http://mrl.nyu.edu/~meyer/jasmin/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://mrl.nyu.edu/~meyer/jasmin/
COMMENT=	Java "assembler" interface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_JAVA=	run
USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/jasmin
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

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
