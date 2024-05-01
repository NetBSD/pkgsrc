# $NetBSD: Makefile,v 1.13 2024/05/01 08:57:22 jperkin Exp $

DISTNAME=	acme-tiny-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme-tiny/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/diafygi/acme-tiny
COMMENT=	Tiny script to issue and renew TLS certs from Let's Encrypt
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} acme-tiny acme-tiny-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
# does not need the libraries/headers, but this way we an use the builtin one
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
