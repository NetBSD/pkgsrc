# $NetBSD: Makefile,v 1.3 2017/01/01 14:43:35 wiz Exp $

DISTNAME=			ruamel.ordereddict-0.4.9
PKGNAME=			${PYPKGPREFIX}-ruamel-ordereddict-0.4.9
CATEGORIES=			devel
MASTER_SITES=			${MASTER_SITE_PYPI:=r/ruamel.ordereddict/}

MAINTAINER=			gde@llew.me
HOMEPAGE=			https://bitbucket.org/ruamel/ordereddict
COMMENT=			Version of dict that keeps keys in insertion resp. sorted order
LICENSE=			mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
