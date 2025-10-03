# $NetBSD: Makefile,v 1.2 2025/10/03 06:33:56 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	liblal-tools-${GNAT_NAME}-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	libadalang-tools
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/libadalang-tools
COMMENT=	Libadalang-based development tools for Ada, library package
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	src/tgen/tgen_rts/tgen.ads
SUBST_MESSAGE.version=	Fix version in ${SUBST_FILES.version}
SUBST_SED.version=	-e 's,0.0,25.0,g'

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
BUILDLINK_DEPMETHOD.templates-parser-25=	full
BUILDLINK_DEPMETHOD.langkit-support-25=		full
BUILDLINK_DEPMETHOD.libadalang-25=		full
.else
MAKE_FLAGS+=					ALL_LIBRARY_TYPES=static
.endif

BUILD_TARGET=		lib
MAKE_FLAGS+=		BUILD_MODE=prod

INSTALL_TARGET=		install-lib install-tgen
INSTALL_MAKE_FLAGS+=	PREFIX=${GNAT_PREFIX}

post-install:
	${CHMOD} -x ${DESTDIR}${GNAT_PREFIX}/share/tgen/tgen_rts/tgen-instr_support.ads

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
.include "../../textproc/ada-templates-parser-25/buildlink3.mk"

.include "../../devel/ada-langkit-support-25/buildlink3.mk"
.include "../../devel/ada-libadalang-25/buildlink3.mk"

# libgpr2 dependencies
.include "../../devel/gmp/buildlink3.mk"
USE_GNU_ICONV=		yes
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
