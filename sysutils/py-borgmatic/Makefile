# $NetBSD: Makefile,v 1.1 2023/11/28 17:21:37 he Exp $

DISTNAME=	borgmatic-1.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=borgmatic-collective/}
GITHUB_PROJECT=	borgmatic
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://torsion.org/borgmatic/
COMMENT=	Configuration-driver backup software
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=   27 37

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.1<0.5:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>0.15.0:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
