# $NetBSD: Makefile,v 1.2 2025/09/13 09:16:25 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	langkit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/langkit
COMMENT=	Tool to create syntactic and semantic analysis engines
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	setup.py
SUBST_MESSAGE.version=	Set version in ${SUBST_FILES.version}
SUBST_SED.version=	-e 's,0.1.0,${PKGVERSION_NOREV},'

.include "../../math/ada-adasat-25/inplace.mk"

pre-configure:
	${MV} ${WRKSRC}/adasat ${WRKSRC}/langkit/

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-mako>=1.1.2:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-funcy>=1.14:../../devel/py-funcy
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-e3-core>=22.6.0:../../devel/py-e3-core
#DEPENDS+=	${PYPKGPREFIX}-gnat-gdb-scripts>=23.2:../../devel/py-gnat-gdb-scripts

TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=2.16.0:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-autopep8>=1.5.2:../../devel/py-autopep8
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.1:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=6.0.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=7.0.1:../../devel/py-importlib-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.7.0:../../devel/py-mccabe
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=1.1.1:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.8.0:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-ptyprocess>=0.7.0:../../sysutils/py-ptyprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.10.0:../../devel/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes>=3.0.1:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-railroad-diagrams>=1.1.0:../../graphics/py-railroad-diagrams
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme>=0.4.3:../../textproc/py-sphinx-rtd-theme
TEST_DEPENDS+=	${PYPKGPREFIX}-types-docutils>=0.18.3:../../textproc/py-types-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-types-gdb>=12.1.2:../../devel/py-types-gdb
TEST_DEPENDS+=	${PYPKGPREFIX}-yapf>=0.30.0:../../devel/py-yapf
TEST_DEPENDS+=	${PYPKGPREFIX}-e3-testsuite>=25.0:../../devel/py-e3-testsuite

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/create-project.py ${DESTDIR}${PREFIX}/bin/create-project${PYVERSSUFFIX}.py

# langkit uses deprecated pipes module
PYTHON_VERSIONS_INCOMPATIBLE+=	313

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
