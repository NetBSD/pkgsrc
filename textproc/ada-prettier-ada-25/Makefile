# $NetBSD: Makefile,v 1.2 2025/10/03 18:14:18 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	prettier-ada
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/prettier-ada
COMMENT=	Port of the Prettier formatter to the Ada
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

PLIST_VARS+=				shlibs

USE_PKGSRC_GCC_RUNTIME?=		no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=				yes
BUILD_TARGET=				all
INSTALL_TARGET=				install-all
BUILDLINK_DEPMETHOD.xmlada-25=		full
BUILDLINK_DEPMETHOD.vss-25=		full
BUILDLINK_DEPMETHOD.libgpr-25=		full
BUILDLINK_DEPMETHOD.gnatcoll-core-25=	full
.else
BUILD_TARGET=				lib
MAKE_FLAGS+=				LIBRARY_TYPE=static
INSTALL_TARGET=				install
.endif

MAKE_FLAGS+=				PREFIX=${DESTDIR}${GNAT_PREFIX} BUILD_MODE=prod

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

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
