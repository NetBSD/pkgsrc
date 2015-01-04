# $NetBSD: Makefile,v 1.19 2015/01/04 03:14:00 dholland Exp $
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

BROKEN_ON_PLATFORM=	SunOS-*-* # needs porting

WRKSRC=		${WRKDIR}/brandy-1.0.16
DOCDIR=		share/doc/brandy
EXAMPLEDIR=	share/examples/brandy
BUILD_TARGET=	nodebug

USE_TOOLS+=		gtar
INSTALLATION_DIRS=	bin ${DOCDIR} ${EXAMPLEDIR}

do-install:
	cd ${WRKSRC}/docs && ${GTAR} -cf - `ls |grep -v .orig` | \
		(cd ${DESTDIR}${PREFIX}/${DOCDIR} && gtar xf -)
	cd ${WRKSRC}/examples && ${GTAR} -cf - [a-z]* | \
		(cd ${DESTDIR}${PREFIX}/${EXAMPLEDIR} && gtar xf -)
	${INSTALL_PROGRAM} ${WRKSRC}/brandy ${DESTDIR}${PREFIX}/bin/brandy

.include "../../mk/bsd.pkg.mk"
