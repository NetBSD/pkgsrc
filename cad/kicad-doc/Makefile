# $NetBSD: Makefile,v 1.12 2022/07/20 16:28:54 tnn Exp $
#

V=		6.0.6
DISTNAME=	kicad-doc-${V}
CATEGORIES=	cad
MASTER_SITES=	https://kicad-downloads.s3.cern.ch/docs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Documentation for the PCB CAD software
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pax
DOCDIR=		${DESTDIR}${PREFIX}/share/doc/kicad

do-build:
	${FIND} ${WRKSRC} -name PaxHeader -print |  ${XARGS} ${RM} -rf

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/share/doc/kicad && ${PAX} -rw . ${DOCDIR}/
	${FIND} ${DOCDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DOCDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
