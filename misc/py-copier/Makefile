# $NetBSD: Makefile,v 1.1 2026/09/03 05:13:15 adam Exp $

DISTNAME=	copier-9.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/copier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/copier-org/copier
COMMENT=	Library for rendering project templates
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-dunamai>=1.7.0:../../devel/py-dunamai
DEPENDS+=	${PYPKGPREFIX}-funcy>=1.17:../../devel/py-funcy
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.6:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jinja2-ansible-filters>=1.3.1:../../textproc/py-jinja2-ansible-filters
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.9.0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.3.6:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-plumbum>=1.6.9:../../devel/py-plumbum
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.4.2:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.7.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-questionary>=1.8.1:../../misc/py-questionary
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	copier

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
