# $NetBSD: Makefile,v 1.7 2012/10/08 13:25:12 asau Exp $
#

DISTNAME=	GDSreader.0.3
PKGNAME=	gdsreader-0.3
CATEGORIES=	cad
MASTER_SITES=	http://home.netcom.com/~serbanp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.netcom.com/~serbanp/
COMMENT=	GDS-II stream file to Postscript and HP/GL converter

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAME}

INSTALLATION_DIRS=	bin ${EXAMPLESDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/test.gds ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/layers.config ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
