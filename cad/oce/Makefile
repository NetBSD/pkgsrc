# $NetBSD: Makefile,v 1.10 2022/03/19 23:55:42 brook Exp $

DISTNAME=	OCE-0.18.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=tpaviot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tpaviot/oce/
COMMENT=	Open CASCADE Community Edition
LICENSE=	gnu-lgpl-v2.1

GITHUB_TAG=	${DISTNAME}
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
SUBST_FILES.prefix=	CMakeFiles/Export/lib/oce/OCE-libraries-release.cmake
.if !empty(OPSYS:MDarwin)
SUBST_SED.prefix=	-e "s|${BUILDLINK_DIR}/lib/lib\([0-9a-zA-Z_-]*\)\.dylib|\1|g"
.else
SUBST_SED.prefix=	-e "s|${BUILDLINK_DIR}/lib/lib\([0-9a-zA-Z_-]*\)\.so|\1|g"
.endif

PLIST_VARS+=	Darwin not_Darwin
.if !empty(OPSYS:MDarwin)
PLIST.Darwin=		yes
.else
PLIST.not_Darwin=	yes
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
