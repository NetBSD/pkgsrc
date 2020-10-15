# $NetBSD: Makefile,v 1.3 2020/10/15 13:46:35 adam Exp $

DISTNAME=	Authlib-0.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Authlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://authlib.org/
COMMENT=	Ultimate Python library in building OAuth and OpenID Connect servers
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
