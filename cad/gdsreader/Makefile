# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:01 jlam Exp $
#

DISTNAME=	GDSreader.0.3
PKGNAME=	gdsreader-0.3
CATEGORIES=	cad
MASTER_SITES=	http://home.netcom.com/~serbanp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.netcom.com/~serbanp/
COMMENT=	GDS-II stream file to Postscript and HP/GL converter

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.gds ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/layers.config ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
