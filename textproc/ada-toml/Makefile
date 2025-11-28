# $NetBSD: Makefile,v 1.1 2025/11/28 20:07:22 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-0.5
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-0.5.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pmderodat/}
GITHUB_PROJECT=	ada-toml
GITHUB_TAG=	v0.5

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/pmderodat/ada-toml
COMMENT=	TOML parser for Ada
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	13

MAKE_FLAGS+=	prefix=${GNAT_PREFIX}

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=	yes
.else
BUILD_TARGET=	build-static
INSTALL_TARGET=	install-static
.endif

pre-test:
	${RUN} cd ${WRKSRC} && \
	${PREFIX}/bin/gprbuild -Pcheckers -XADA_TOML_BUILD_MODE=dev -p ${GPRBUILD_OPTIONS}

do-test:
	${RUN} cd ${WRKSRC} && \
	PYTHON_EXEC_PATH=${TOOL_PYTHONBIN:Q} ${TOOL_PYTHONBIN:Q} run-tests.py -E

.if ${PKGSRC_RUN_TEST:tl} == "yes"
.include "../../lang/python/tool.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.endif

TEST_DEPENDS+=	${PYPKGPREFIX}-e3-core>=22.6.0:../../devel/py-e3-core
TEST_DEPENDS+=	${PYPKGPREFIX}-e3-testsuite>=25.0:../../devel/py-e3-testsuite

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/relocatable\/|static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
