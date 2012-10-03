# $NetBSD: Makefile,v 1.14 2012/10/03 11:43:30 asau Exp $

DISTNAME=	beav_1.40.orig
PKGNAME=	beav-1.40.18
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/b/beav/}

PATCHFILES=	beav_1.40-18.diff.gz
PATCH_SITES=	${MASTER_SITE_DEBIAN:=pool/main/b/beav/}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	bad@NetBSD.org
COMMENT=	Binary Editor And Viewer, a full featured binary file editor

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}/beav-140
MAKE_ENV+=	SED=${SED:Q}
BUILD_TARGET=	beav

SUBST_CLASSES+=	docpath
SUBST_FILES.docpath=	beav.1
SUBST_STAGE.docpath=	post-build
SUBST_SED.docpath=	-e 's,/usr/share/doc/,${PREFIX}/share/doc,'
SUBST_MESSAGE.docpath=	Fixing path in documentation.

.include "../../mk/bsd.pkg.mk"
