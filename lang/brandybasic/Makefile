# $NetBSD: Makefile,v 1.2 2001/02/17 09:06:59 agc Exp $
#

DISTNAME=       b105
PKGNAME=        brandybasic-1.05
CATEGORIES=     lang
MASTER_SITES=   http://www.argonet.co.uk/users/dave_daniels/
EXTRACT_SUFX=   .tgz

MAINTAINER=     abs
HOMEPAGE=       http://www.argonet.co.uk/users/dave_daniels/
COMMENT=	Brandy Basic V interpreter - Acorn ARM Computers BASIC dialect

WRKSRC=		${WRKDIR}/brandy-105

DOCDIR=		${PREFIX}/share/doc/brandy
EXAMPLEDIR=	${PREFIX}/share/examples/brandy

MAKEFILE=	makefile

do-install:
	${MKDIR} ${DOCDIR}
	${MKDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/docs && ${GTAR} -cf - `ls |grep -v .orig` | (cd ${DOCDIR} && tar xf -)
	cd ${WRKSRC}/examples && ${GTAR} -cf - [a-z]* | (cd ${EXAMPLEDIR} && tar xf -)
	${INSTALL_PROGRAM} ${WRKSRC}/brandy ${PREFIX}/bin/brandy

.include "../../mk/bsd.pkg.mk"
