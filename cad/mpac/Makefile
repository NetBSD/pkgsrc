# $NetBSD: Makefile,v 1.5 2004/03/08 20:27:13 minskim Exp $
#

DISTNAME=	mpac-0.2.2
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://goemon.polito.it/ftp/pub/software/lethal/Elettronica/antenna/

MAINTAINER=	dmcmahill@NetBSD.org
COMMENT=	Microstrip Patch Antenna Calculator

DEPENDS+=	tk>=8.1:../../x11/tk83

do-build:
	${SED} 's;patch.gif;${PREFIX}/share/mpac/patch.gif;g' ${WRKSRC}/mpac.tcl > ${WRKSRC}/mpac

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mpac ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mpac
	${INSTALL_DATA} ${WRKSRC}/patch.gif ${PREFIX}/share/mpac

.include "../../mk/bsd.pkg.mk"
