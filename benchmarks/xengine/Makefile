# $NetBSD: Makefile,v 1.13 2005/03/24 21:12:51 wiz Exp $

DISTNAME=	xengine-1.0.1
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/comp.sources.x/volume09/xengine/
DISTFILES=	part01.z patch1.z

PATCH_DIST_STRIP=	-p1	# no ${PATCHFILES} but used below

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	Reciprocating engine for X

BUILD_DEPENDS=	gsharutils>=4.2.1:../../archivers/gsharutils

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	xengine
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
