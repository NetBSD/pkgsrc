# $NetBSD: Makefile,v 1.10 2012/10/08 13:25:14 asau Exp $
#

DISTNAME=	mpac-0.2.2
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://goemon.polito.it/ftp/pub/software/lethal/Elettronica/antenna/

MAINTAINER=	dmcmahill@NetBSD.org
COMMENT=	Microstrip Patch Antenna Calculator

DEPENDS+=	tk>=8.1:../../x11/tk

INSTALLATION_DIRS=	bin

do-build:
	${SED} 's;patch.gif;${PREFIX}/share/mpac/patch.gif;g' ${WRKSRC}/mpac.tcl > ${WRKSRC}/mpac

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mpac ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mpac
	${INSTALL_DATA} ${WRKSRC}/patch.gif ${DESTDIR}${PREFIX}/share/mpac

.include "../../mk/bsd.pkg.mk"
