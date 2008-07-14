# $NetBSD: Makefile,v 1.6 2008/07/14 12:55:59 joerg Exp $
#

DISTNAME=	GDSreader.0.3
PKGNAME=	gdsreader-0.3
CATEGORIES=	cad
MASTER_SITES=	http://home.netcom.com/~serbanp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.netcom.com/~serbanp/
COMMENT=	GDS-II stream file to Postscript and HP/GL converter

PKG_DESTDIR_SUPPORT=	user-destdir

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAME}

INSTALLATION_DIRS=	bin ${EXAMPLESDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/test.gds ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/layers.config ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
