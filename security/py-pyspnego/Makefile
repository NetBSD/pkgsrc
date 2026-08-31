# $NetBSD: Makefile,v 1.14 2026/08/31 12:04:07 adam Exp $

DISTNAME=	pyspnego-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspnego/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jborean93/pyspnego
COMMENT=	Windows Negotiate Authentication Client and Server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# kerberos
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.6.0:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-krb5>=0.3.0:../../security/py-krb5

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pyspnego-parse

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
