# $NetBSD: Makefile,v 1.15 2007/11/20 22:11:50 rillig Exp $
#

DISTNAME=	b116
PKGNAME=	brandybasic-1.0.16
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://jaguar.orpheusweb.co.uk/
# http://jaguar.orpheusweb.co.uk/brandy_119.tgz
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://jaguar.orpheusweb.co.uk/branpage.html
COMMENT=	Brandy Basic V interpreter - Acorn ARM Computers BASIC dialect

NOT_FOR_PLATFORM=	SunOS-*-* # needs porting

WRKSRC=		${WRKDIR}/brandy-1.0.16
DOCDIR=		${PREFIX}/share/doc/brandy
EXAMPLEDIR=	${PREFIX}/share/examples/brandy
BUILD_TARGET=	nodebug

USE_TOOLS+=		gtar
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/docs && ${GTAR} -cf - `ls |grep -v .orig` | (cd ${DOCDIR} && tar xf -)
	cd ${WRKSRC}/examples && ${GTAR} -cf - [a-z]* | (cd ${EXAMPLEDIR} && tar xf -)
	${INSTALL_PROGRAM} ${WRKSRC}/brandy ${PREFIX}/bin/brandy

.include "../../mk/bsd.pkg.mk"
