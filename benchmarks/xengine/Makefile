# $NetBSD: Makefile,v 1.6 2001/09/09 20:36:15 agc Exp $
# FreeBSD Id: ports/benchmarks/xengine/Makefile,v 1.9 2000/02/02 22:31:24 mharo Exp

DISTNAME=	xengine-1.0.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/comp.sources.x/volume09/xengine/
DISTFILES=	part01.z patch1.z

PATCH_DIST_STRIP=	-p1	# no ${PATCHFILES} but used below

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	Reciprocating engine for X

BUILD_DEPENDS=	gsharutils-4.2.1:../../archivers/gsharutils

DIST_SUBDIR=	xengine
WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

EXTRACT_CMD=	zcat ${DOWNLOADED_DISTFILE} | gunshar

pre-patch:
	@cd ${WRKSRC} ; ${PATCH} ${PATCH_DIST_ARGS} < xengine.patch1

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xengine
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xengine
	@${ECHO} ""
	@${ECHO} "Example value:"
	@${ECHO} "   1067 RPMs with P100, Winner 2000PRO/X, resolution: 1152x900"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
