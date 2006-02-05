# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:22 joerg Exp $
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
	${INSTALL_SCRIPT} ${WRKSRC}/mpac ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mpac
	${INSTALL_DATA} ${WRKSRC}/patch.gif ${PREFIX}/share/mpac

.include "../../mk/bsd.pkg.mk"
