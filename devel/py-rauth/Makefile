# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:35 wiz Exp $

DISTNAME=	rauth-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rauth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/litl/rauth
COMMENT=	Python library for OAuth 1.0/a, 2.0, and Ofly consumers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.3:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
