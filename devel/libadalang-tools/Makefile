# $NetBSD: Makefile,v 1.1 2025/09/07 07:20:48 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	libadalang-tools
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/libadalang-tools
COMMENT=	Libadalang-based development tools for Ada
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	src/tgen/tgen_rts/tgen.ads
SUBST_MESSAGE.version=	Fix version in ${SUBST_FILES.version}
SUBST_SED.version=	-e 's,0.0,25.0,g'

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
