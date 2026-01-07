# $NetBSD: Makefile,v 1.3 2026/01/07 23:33:45 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	lib${GITHUB_PROJECT}-${GNAT_NAME}-${GITHUB_TAG}.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatdoc
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatdoc
COMMENT=	GNAT Documentation Generation Tool, library package 25
LICENSE=	apache-2.0

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

USE_GCC_RUNTIME=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Replace version and date in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	source/gnatdoc/gnatdoc-version.ads
SUBST_SED.version=	-e "s,%VERSION% (%DATE%),${GITHUB_TAG} (20241217),"

PLIST_VARS+=	shlibs

USE_PKGSRC_GCC_RUNTIME?=			no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=					yes
MAKE_FLAGS+=					ALL_LIBRARY_TYPES='static static-pic relocatable'
BUILDLINK_DEPMETHOD.xmlada-25=			full
BUILDLINK_DEPMETHOD.libgpr-25=			full
BUILDLINK_DEPMETHOD.gnatcoll-core-25=		full
BUILDLINK_DEPMETHOD.gnatcoll-bindings-25=	full
BUILDLINK_DEPMETHOD.adasat-25=			full
BUILDLINK_DEPMETHOD.libgpr2-25=			full
BUILDLINK_DEPMETHOD.vss-25=			full
BUILDLINK_DEPMETHOD.prettier-ada-25=		full
BUILDLINK_DEPMETHOD.langkit-support-25=		full
BUILDLINK_DEPMETHOD.libadalang-25=		full
BUILDLINK_DEPMETHOD.markdown-25=		full
.else
MAKE_FLAGS+=					ALL_LIBRARY_TYPES=static
.endif

MAKE_FLAGS+=		BUILD_MODE=prod
BUILD_TARGET=		build-libgnatdoc

INSTALL_MAKE_FLAGS=	PREFIX=${GNAT_PREFIX}
INSTALL_TARGET=		install-libgnatdoc

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.${SHLIB_EXT}.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"
.include "../../devel/ada-langkit-support-25/buildlink3.mk"
.include "../../devel/ada-libadalang-25/buildlink3.mk"
.include "../../textproc/ada-markdown-25/buildlink3.mk"

# libgpr2 dependencies
.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
