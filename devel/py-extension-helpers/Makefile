# $NetBSD: Makefile,v 1.1 2020/12/19 14:12:30 mef Exp $

DISTNAME=	extension-helpers-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/extension-helpers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/extension-helpers/
COMMENT=	Helpers to assist building packages with C/Cython extension
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

# adhoc fix to convert below
# extension-helpers-0.1-py3.8.egg-info
# extension_helpers-0.0.0-py3.8.egg-info

EGG_INFODIR=	${DISTNAME:S/-/_/:S/0.1/0.0.0/}-py${PYVERSSUFFIX}.egg-info


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
