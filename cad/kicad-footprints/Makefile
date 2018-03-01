# $NetBSD: Makefile,v 1.3 2018/03/01 13:59:11 mef Exp $
#

V=		4.0.7
DISTNAME=	kicad-footprints-${V}
CATEGORIES=	cad
MASTER_SITES=	http://downloads.kicad-pcb.org/libraries/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://kicad-pcb.org/
COMMENT=	components footprints for the PCB CAD software
LICENSE=	gnu-gpl-v2

MODDIR=		${DESTDIR}${PREFIX}/share/kicad/modules

do-build:
do-install:
	${INSTALL_DATA_DIR} ${MODDIR}
	cd ${WRKSRC}; \
	find . -name PaxHeader -print | xargs rm -rf; \
	for d in *; do \
		${INSTALL_DATA_DIR} ${MODDIR}/$$d; \
	done;
	cd ${WRKSRC}; \
	for f in */*; do \
		${INSTALL_DATA} $$f ${MODDIR}/$$f; \
	done;

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
