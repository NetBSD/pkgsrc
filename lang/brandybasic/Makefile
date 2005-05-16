# $NetBSD: Makefile,v 1.10 2005/05/16 01:15:32 jlam Exp $
#

DISTNAME=	b116
PKGNAME=	brandybasic-1.0.16
CATEGORIES=	lang
MASTER_SITES=	http://www.argonet.co.uk/users/dave_daniels/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.argonet.co.uk/users/dave_daniels/
COMMENT=	Brandy Basic V interpreter - Acorn ARM Computers BASIC dialect

WRKSRC=		${WRKDIR}/brandy-1.0.16
DOCDIR=		${PREFIX}/share/doc/brandy
EXAMPLEDIR=	${PREFIX}/share/examples/brandy
BUILD_TARGET=	nodebug

PKGSRC_USE_TOOLS+=	gtar

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/docs && ${GTAR} -cf - `ls |grep -v .orig` | (cd ${DOCDIR} && tar xf -)
	cd ${WRKSRC}/examples && ${GTAR} -cf - [a-z]* | (cd ${EXAMPLEDIR} && tar xf -)
	${INSTALL_PROGRAM} ${WRKSRC}/brandy ${PREFIX}/bin/brandy

.include "../../mk/bsd.pkg.mk"
