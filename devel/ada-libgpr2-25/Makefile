# $NetBSD: Makefile,v 1.2 2025/10/09 20:49:50 dkazankov Exp $

DISTNAME=	gpr2-${GITHUB_TAG}
PKGNAME=	libgpr2-${GNAT_NAME}-${GITHUB_TAG}.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gpr
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gpr
COMMENT=	Parser for GPR Project files, release 25
LICENSE=	apache-2.0 OR gnu-gpl-v3

GITHUB_SUBMODULES+=	AdaCore	gprconfig_kb	${GITHUB_TAG}	gprconfig_kb

USE_TOOLS+=	gmake realpath

HAS_CONFIGURE=	yes

USE_LANGUAGES=	c ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		fixparam
SUBST_STAGE.fixparam=	pre-configure
SUBST_FILES.fixparam=	Makefile
SUBST_MESSAGE.fixparam=	Fix realpath parameter
SUBST_SED.fixparam=	-e 's, --relative-to=. , ,g'
.endif

CONFIG_SHELL=		${MAKE_PROGRAM} -f
CONFIGURE_SCRIPT=	${WRKSRC}/Makefile
CONFIGURE_ARGS=		setup

CONFIGURE_ARGS+=			prefix=${DESTDIR}${GNAT_PREFIX}
CONFIGURE_ARGS+=			GPR2_BUILD=release
CONFIGURE_ARGS+=			GPR2KBDIR=gprconfig_kb/db

PLIST_VARS+=				shlibs

USE_PKGSRC_GCC_RUNTIME?=			no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=					yes
CONFIGURE_ARGS+=				ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada-25=			full
BUILDLINK_DEPMETHOD.libgpr-25=			full
BUILDLINK_DEPMETHOD.gnatcoll-core-25=		full
BUILDLINK_DEPMETHOD.gnatcoll-bindings-25=	full
.else
CONFIGURE_ARGS+=				ENABLE_SHARED=no
.endif

BUILD_TARGET=	build-libs
INSTALL_TARGET=	install-libs

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"

.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
