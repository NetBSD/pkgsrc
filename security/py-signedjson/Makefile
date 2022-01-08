# $NetBSD: Makefile,v 1.3 2022/01/08 16:14:31 adam Exp $

DISTNAME=	signedjson-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/signedjson/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Signs JSON objects with ED25519 signatures
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-canonicaljson>=1.0.0:../../devel/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-nacl>=0.3.0:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.5:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.0.1:../../devel/py-unpaddedbase64
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
