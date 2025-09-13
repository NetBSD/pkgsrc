# $NetBSD: Makefile,v 1.3 2025/09/13 09:16:25 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-25.0.0
PKGNAME=	${PYPKGPREFIX}-liblktlang-25.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	langkit
GITHUB_TAG=	v25.0.0

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/langkit
COMMENT=	LKT parser written on top of Langkit
LICENSE=	apache-2.0

USE_LANGUAGES=	c ada

USE_TOOLS+=	pax gmake

HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

CREATE_INPLACE_BUILD_TARGETS=	static-pic

.include "../../textproc/ada-xmlada-25/inplace.mk"
.include "../../devel/ada-libgpr-25/inplace.mk"
.include "../../devel/ada-gnatcoll-core-25/inplace.mk"
.include "../../textproc/ada-vss-25/inplace.mk"
.include "../../textproc/ada-prettier-ada-25/inplace.mk"
.include "../../math/ada-adasat-25/inplace.mk"

GNATCOLL_INPLACE_BINDINGS=	gmp iconv
.include "../../devel/ada-gnatcoll-bindings-25/inplace.mk"

# Build shared encapsulated liblktlang which is used by python lib.
# It requires use of libraries built in-place because ada pkgsrc libraries
# use static build by default, but we need static-pic libs to build
# encapsulated ada library.
do-configure: ${INPLACE_BUILD_TARGETS}
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	    LANGKIT_SUPPORT_LIBRARY_TYPE=static-pic \
	    LIBLKTLANG_LIBRARY_TYPE=relocatable LIBLKTLANG_STANDALONE=encapsulated \
	${PYTHONBIN:Q} manage.py make \
	    --no-mypy --lib=lkt --generate-auto-dll-dirs \
	    --build-mode=prod --library-types=static-pic \
	    --gargs=${GPRBUILD_OPTIONS:S/\${CFLAGS}/${CFLAGS}/:S/\${LDFLAGS}/${LDFLAGS}/:Q}

post-configure:
	${CP} ${WRKSRC}/contrib/lkt/build/lib/relocatable/prod/liblktlang.${SHLIB_EXT} \
	    ${WRKSRC}/contrib/lkt/build/python/liblktlang/liblktlang.${SHLIB_EXT}

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Set version in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-configure
SUBST_FILES.version=	contrib/lkt/build/python/setup.py
SUBST_SED.version=	-e "s,0.1,${PKGVERSION_NOREV},"

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Replacing python interpreter in ${SUBST_FILES.python}
SUBST_STAGE.python=	post-configure
SUBST_FILES.python=	contrib/lkt/build/scripts/lkt_playground
SUBST_SED.python=	-e "s,/usr/bin/env python,${PYTHONBIN},"

PYSETUPSUBDIR=		contrib/lkt/build/python

INSTALLATION_DIRS+=	bin

pre-install:
	${INSTALL_SCRIPT} \
	    ${WRKSRC}/contrib/lkt/build/scripts/lkt_playground \
	    ${DESTDIR}${PREFIX}/bin/lkt_playground${PYVERSSUFFIX}

.include "../../devel/gprbuild/buildlink3.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-langkit-25.*:../../devel/py-langkit

# langkit uses deprecated pipes module
PYTHON_VERSIONS_INCOMPATIBLE+=	313

.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
