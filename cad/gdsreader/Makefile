# $NetBSD: Makefile,v 1.1.1.1 2002/12/14 02:18:25 dmcmahill Exp $
#

DISTNAME=	GDSreader.0.3
PKGNAME=	gdsreader-0.3
CATEGORIES=	cad
MASTER_SITES=	http://home.netcom.com/~serbanp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.netcom.com/~serbanp/
COMMENT=	GDS-II stream file to Postscript and HP/GL converter

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.gds ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/layers.config ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
