# $NetBSD: Makefile,v 1.5 2003/03/29 12:41:24 jmmv Exp $
#

DISTNAME=       b110
PKGNAME=        brandybasic-1.0.10
WRKSRC=		${WRKDIR}/brandy-1.0.10
CATEGORIES=     lang
MASTER_SITES=   http://www.argonet.co.uk/users/dave_daniels/
EXTRACT_SUFX=   .tgz

MAINTAINER=     abs
HOMEPAGE=       http://www.argonet.co.uk/users/dave_daniels/
COMMENT=	Brandy Basic V interpreter - Acorn ARM Computers BASIC dialect

DOCDIR=		${PREFIX}/share/doc/brandy
EXAMPLEDIR=	${PREFIX}/share/examples/brandy

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/docs && ${GTAR} -cf - `ls |grep -v .orig` | (cd ${DOCDIR} && tar xf -)
	cd ${WRKSRC}/examples && ${GTAR} -cf - [a-z]* | (cd ${EXAMPLEDIR} && tar xf -)
	${INSTALL_PROGRAM} ${WRKSRC}/brandy ${PREFIX}/bin/brandy

.include "../../mk/bsd.pkg.mk"
