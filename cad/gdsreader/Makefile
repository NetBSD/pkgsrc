# $NetBSD: Makefile,v 1.5 2008/06/20 01:09:08 joerg Exp $
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
