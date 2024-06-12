# $NetBSD: Makefile,v 1.4 2024/06/12 05:59:00 adam Exp $

DISTNAME=	pyspnego-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspnego/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jborean93/pyspnego
COMMENT=	Windows Negotiate Authentication Client and Server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
# kerberos
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.6.0:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-krb5>=0.3.0:../../security/py-krb5

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyspnego-parse pyspnego-parse-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
