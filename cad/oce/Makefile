# $NetBSD: Makefile,v 1.12 2023/01/29 21:14:24 ryoon Exp $

DISTNAME=	OCE-0.18.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=tpaviot/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tpaviot/oce/
COMMENT=	Open CASCADE Community Edition
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/oce-${DISTNAME}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CHECK_PORTABILITY_SKIP+=	samples/qt/*

# mk/configure/cmake.mk disables rpath handling
# but we need it for a lib subpath
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/oce

CMAKE_ARGS+=	-DOCE_INSTALL_PREFIX:PATH=${PREFIX}

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	CMakeFiles/Export/*/OCE-libraries-release.cmake
.if ${OPSYS} == Darwin
SUBST_SED.prefix=	-e "s|${BUILDLINK_DIR}/lib/lib\([0-9a-zA-Z_-]*\)\.dylib|\1|g"
.else
SUBST_SED.prefix=	-e "s|${BUILDLINK_DIR}/lib/lib\([0-9a-zA-Z_-]*\)\.so|\1|g"
.endif

PLIST_VARS+=		Darwin not_Darwin
.if ${OPSYS} == Darwin
PLIST.Darwin=		yes
.else
PLIST.not_Darwin=	yes
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
