# $NetBSD: Makefile,v 1.2 2025/09/22 18:26:02 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	adasat-${GNAT_NAME}-25.0.0
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	AdaSAT
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/AdaSAT
COMMENT=	Implementation of a DPLL-based SAT solver in Ada, release 25
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
BUILD_TARGET=			all-libs
INSTALL_TARGET=			install
.else
BUILD_TARGET=			lib
INSTALL_TARGET=			install-lib
LIBRARY_TYPE=			static
MAKE_FLAGS+=			LIBRARY_TYPE=${LIBRARY_TYPE}
INSTALL_MAKE_FLAGS+=		LIBRARY_TYPE=${LIBRARY_TYPE}
.endif

MAKE_FLAGS+=			BUILD_MODE=prod
INSTALL_MAKE_FLAGS+=		INSTALL_DIR=${DESTDIR}${GNAT_PREFIX}

.if ${PKGSRC_RUN_TEST:tl} == "yes"
.include "../../lang/python/tool.mk"
.endif

TEST_TARGET=	test

TEST_MAKE_FLAGS+=	PYTHON=${TOOL_PYTHONBIN} GPR_PROJECT_PATH=${WRKSRC}

TEST_DEPENDS+=	${PYPKGPREFIX}-e3-core>=22.6.0:../../devel/py-e3-core
TEST_DEPENDS+=	${PYPKGPREFIX}-e3-testsuite>=25.0:../../devel/py-e3-testsuite

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
