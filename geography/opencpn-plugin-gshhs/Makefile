# $NetBSD: Makefile,v 1.2 2017/09/03 08:53:09 wiz Exp $
#

VERSION=	2.2.4
DISTNAME=	opencpn-gshhs_${VERSION}
PKGNAME=	opencpn-plugin-gshhs-${VERSION}
CATEGORIES=	geography
EXTRACT_SUFX=	.tar.xz
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencpnplugins/opencpn_packaging_data/}

WRKSRC=		${WRKDIR}/opencpn/gshhs/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/ocpn/
COMMENT=	complete OpenCPN shoreline database
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=
USE_TOOLS=

do-build:
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/opencpn/gshhs
	for file in \
	    poly-f-1.dat poly-h-1.dat poly-i-1.dat poly-l-1.dat \
	    wdb_borders_f.b wdb_borders_h.b wdb_borders_i.b wdb_borders_l.b \
	    wdb_rivers_f.b wdb_rivers_h.b wdb_rivers_i.b wdb_rivers_l.b \
	    ; do \
		${INSTALL_DATA}  ${WRKSRC}/$$file \
		    ${DESTDIR}${PREFIX}/share/opencpn/gshhs/; \
	done

.include "../../mk/bsd.pkg.mk"

