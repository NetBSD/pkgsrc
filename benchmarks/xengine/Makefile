# $NetBSD: Makefile,v 1.24 2009/07/08 14:38:28 joerg Exp $

DISTNAME=	xengine-1.0.1
PKGREVISION=	4
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.42.org/pub/OLD/x/xengine/
DISTFILES=	part01.z patch1.z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Reciprocating engine for X

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	xengine
USE_IMAKE=	yes
PATCH_DIST_STRIP=	-p1

USE_TOOLS+=	gzcat patch sed

EXTRACT_CMD=	${GZCAT} $$extract_file | ${SED} "1,/\#!/d" | ${SH}

pre-configure:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < xengine.patch1

INSTALLATION_DIRS=	share/doc/xengine

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xengine
	@${ECHO} ""
	@${ECHO} "Example value:"
	@${ECHO} "   1067 RPMs with P100, Winner 2000PRO/X, resolution: 1152x900"
	@${ECHO} ""

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
