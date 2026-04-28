# $NetBSD: Makefile,v 1.17 2026/04/28 09:55:08 adam Exp $

DISTNAME=	acme_tiny-5.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme-tiny/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/diafygi/acme-tiny
COMMENT=	Tiny script to issue and renew TLS certs from Let's Encrypt
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	acme-tiny

.include "../../lang/python/wheel.mk"
# does not need the libraries/headers, but this way we can use the builtin one
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
