# $NetBSD: Makefile,v 1.10 2023/07/30 15:32:49 adam Exp $

DISTNAME=	signedjson-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/signedjson/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Signs JSON objects with ED25519 signatures
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-canonicaljson>=1.0.0:../../devel/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-nacl>=0.3.0:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.0.1:../../devel/py-unpaddedbase64
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-unpaddedbase64

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
