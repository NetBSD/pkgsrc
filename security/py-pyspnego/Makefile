# $NetBSD: Makefile,v 1.2 2023/08/29 06:18:33 adam Exp $

DISTNAME=	pyspnego-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspnego/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jborean93/pyspnego
COMMENT=	Windows Negotiate Authentication Client and Server
LICENSE=	mit

# kerberos
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.6.0:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-krb5>=0.3.0:../../security/py-krb5

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyspnego-parse pyspnego-parse-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
