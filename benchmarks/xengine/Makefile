# $NetBSD: Makefile,v 1.16 2005/08/23 10:26:17 hira Exp $

DISTNAME=	xengine-1.0.1
PKGREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/comp.sources.x/volume09/xengine/
DISTFILES=	part01.z patch1.z

PATCHFILES=		# no ${PATCHFILES} but runs "do-distribution-patch"
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	Reciprocating engine for X

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	xengine
USE_IMAKE=	yes

USE_TOOLS+=	gzcat patch sed

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SED} "1,/\#!/d" | ${SH}

do-distribution-patch:
	@cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < xengine.patch1

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xengine
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xengine
	@${ECHO} ""
	@${ECHO} "Example value:"
	@${ECHO} "   1067 RPMs with P100, Winner 2000PRO/X, resolution: 1152x900"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
