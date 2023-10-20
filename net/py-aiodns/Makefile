# $NetBSD: Makefile,v 1.2 2023/10/20 07:27:58 wiz Exp $

DISTNAME=	aiodns-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiodns/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/aiodns
COMMENT=	Simple DNS resolver for asyncio
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cares>=4:../../net/py-cares

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
