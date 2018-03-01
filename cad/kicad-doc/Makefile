# $NetBSD: Makefile,v 1.4 2018/03/01 13:59:11 mef Exp $
#

V=		4.0.7
DISTNAME=	kicad-doc-${V}
CATEGORIES=	cad
MASTER_SITES=	http://downloads.kicad-pcb.org/docs/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://kicad-pcb.org/
COMMENT=	Documentation for the PCB CAD software
LICENSE=	gnu-gpl-v2

DOCDIR=		${DESTDIR}${PREFIX}/share/doc/kicad

do-build:
do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${CP} -R ${WRKSRC}/share/doc/kicad/help ${DOCDIR}/
	${FIND} ${DOCDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DOCDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
