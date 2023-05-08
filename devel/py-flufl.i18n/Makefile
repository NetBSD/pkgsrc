# $NetBSD: Makefile,v 1.7 2023/05/08 20:43:29 markd Exp $

DISTNAME=	flufl.i18n-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.i18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flufli18n.readthedocs.io/
COMMENT=	High level API for Python internationalization
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
