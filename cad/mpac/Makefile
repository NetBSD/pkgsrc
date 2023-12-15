# $NetBSD: Makefile,v 1.11 2023/12/15 18:38:36 zafer Exp $
#

DISTNAME=	mpac-0.2.2
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	https://www.aydogan.net/distfiles/cad/

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
