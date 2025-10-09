# $NetBSD: Makefile,v 1.6 2025/10/09 17:52:44 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-${GITHUB_TAG}.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-core
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoll-core
COMMENT=	The GNAT Components Collection (GNATcoll) - Core packages, release 25
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

USE_LANGUAGES=	c ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Change version in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	core/VERSION minimal/VERSION projects/VERSION
SUBST_SED.version=	-e "s,25.0,${GITHUB_TAG},"

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		ldl
SUBST_MESSAGE.ldl=	Fix extra libs on NetBSD in ${SUBST_FILES.ldl}
SUBST_STAGE.ldl=	post-extract
SUBST_FILES.ldl=	core/gnatcoll_core.gpr
SUBST_SED.ldl=		-e "s,\"-ldl\",\"\","

SUBST_CLASSES+=		opendir
SUBST_MESSAGE.opendir=	Replace opendir with __gnatcoll_opendir in ${SUBST_FILES.opendir}
SUBST_STAGE.opendir=	post-extract
SUBST_FILES.opendir=	core/src/os/unix/gnatcoll-os-libc-dirent.ads
SUBST_SED.opendir=	-e "s,\"opendir\",\"__gnatcoll_opendir\","

SUBST_CLASSES+=		unix
SUBST_MESSAGE.unix=	Use BSD implementation in ${SUBST_FILES.unix}
SUBST_STAGE.unix=	post-extract
SUBST_FILES.unix=	core/gnatcoll_core.gpr
SUBST_SED.unix=		-e "s,\"gnatcoll-os-libc_constants__linux.ads\",\"gnatcoll-os-libc_constants__bsd.ads\","
.endif

MAKE_FLAGS+=		PYTHON=${TOOL_PYTHONBIN:Q} prefix=${DESTDIR}${GNAT_PREFIX} BUILD=PROD

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
MAKE_FLAGS+=			ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada-25=	full
BUILDLINK_DEPMETHOD.libgpr-25=	full
.else
MAKE_FLAGS+=			ENABLE_SHARED=no
.endif

TEST_TARGET=	test
TEST_ENV+=	PYTHON_EXEC_PATH=${TOOL_PYTHONBIN:Q}

TEST_DEPENDS+=	${PYPKGPREFIX}-e3-core>=22.6.0:../../devel/py-e3-core
TEST_DEPENDS+=	${PYPKGPREFIX}-e3-testsuite>=25.0:../../devel/py-e3-testsuite

pre-install:
	${RUN} ${MKDIR} ${DESTDIR}${GNAT_PREFIX}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
