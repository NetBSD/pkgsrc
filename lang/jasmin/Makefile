# $NetBSD: Makefile,v 1.3 2002/05/21 13:59:55 jschauma Exp $
#

DISTNAME=	jasmin-1.06
CATEGORIES=     lang
MASTER_SITES=	http://www.cat.nyu.edu/meyer/jasmin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cat.nyu.edu/meyer/jasmin/
COMMENT=	Java "assembler" interface

DEPENDS=	sun-jre>=1.3.1.0.1:../../lang/sun-jre13

WRKSRC=		${WRKDIR}/jasmin

NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/bin/jasmin ${WRKSRC}/bin/jasmin.patch && \
		${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/bin/jasmin.patch > ${WRKSRC}/bin/jasmin && \
		${CHMOD} 755 ${WRKSRC}/bin/jasmin
	${CHMOD} -R ugo+rX ${WRKSRC}/
	${RM} ${WRKSRC}/bin/jasmin.patch

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/jasmin
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}/jasmin
	${LN} -s ${PREFIX}/jasmin/bin/jasmin ${PREFIX}/bin/jasmin

.include "../../mk/bsd.pkg.mk"
