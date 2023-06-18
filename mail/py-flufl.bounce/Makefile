# $NetBSD: Makefile,v 1.8 2023/06/18 05:39:37 adam Exp $

DISTNAME=	flufl.bounce-4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.bounce/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fluflbounce.readthedocs.io/en/latest/
COMMENT=	Email bounce detectors
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface

TOOL_DEPENDS+=	${PYPKGPREFIX}-nose2-[0-9]*:../../devel/py-nose2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
