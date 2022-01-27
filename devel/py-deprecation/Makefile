# $NetBSD: Makefile,v 1.15 2022/01/27 11:35:02 wiz Exp $

DISTNAME=	deprecation-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deprecation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://deprecation.readthedocs.io/
COMMENT=	Library to handle automated deprecations
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
