# $NetBSD: Makefile,v 1.1 2025/09/07 07:48:27 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	lib${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatformat
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatformat
COMMENT=	Opinionated code formatter for the Ada language, library package
LICENSE=	apache-2.0

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

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
.else
MAKE_FLAGS+=					ALL_LIBRARY_TYPES=static
.endif

MAKE_FLAGS+=		BUILD_MODE=prod
BUILD_TARGET=		lib

INSTALL_MAKE_FLAGS=	PREFIX=${GNAT_PREFIX}
INSTALL_TARGET=		install-lib

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

# libgpr2 dependencies
.include "../../devel/gmp/buildlink3.mk"
USE_GNU_ICONV=		yes
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
