# $NetBSD: Makefile,v 1.3 2026/01/07 23:33:45 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	libadalang-tools
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/libadalang-tools
COMMENT=	Libadalang-based development tools for Ada
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version1
SUBST_MESSAGE.version1=	Replace version,year and type in ${SUBST_FILES.version1}
SUBST_STAGE.version1=	post-extract
SUBST_FILES.version1=	src/utils-versions.ads
SUBST_SED.version1=	-e "s,\"dev\",\"${GITHUB_TAG}\","
SUBST_SED.version1+=	-e "s,\"unknown\",\"2025\","
SUBST_SED.version1+=	-e "s,= Gnatpro;,= GPL;,"

SUBST_CLASSES+=		version2
SUBST_STAGE.version2=	post-extract
SUBST_FILES.version2=	src/tgen/tgen_rts/tgen.ads
SUBST_MESSAGE.version2=	Fix version in ${SUBST_FILES.version2}
SUBST_SED.version2=	-e 's,0.0,${GITHUB_TAG},g'

# Rename executables to prevent name conflict with ASIS
#SUBST_CLASSES+=	names
#SUBST_MESSAGE.names=	Fix executable names in ${SUBST_FILES.names}
#SUBST_STAGE.names=	post-extract
#SUBST_FILES.names=	src/build.gpr
#SUBST_SED.names=	-e "s,\"gnatpp\",\"lalgnatpp\"," \
#			-e "s,\"gnatmetric\",\"lalgnatmetric\"," \
#			-e "s,\"gnatstub\",\"lalgnatstub\"," \
#			-e "s,\"gnattest\",\"lalgnattest\","

BUILD_TARGET=		bin
MAKE_FLAGS=		BUILD_MODE=prod

INSTALL_TARGET=		install-bin-strip

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin \( -type f -or -type l \) -print | ${SORT};

CHECK_PIE_SKIP+=	bin/*

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"
.include "../../textproc/ada-templates-parser-25/buildlink3.mk"

.include "../../devel/ada-langkit-support-25/buildlink3.mk"
.include "../../devel/ada-libadalang-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
