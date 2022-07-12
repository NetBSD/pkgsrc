# $NetBSD: Makefile,v 1.12 2022/07/12 09:08:27 wiz Exp $

DISTNAME=	oauth2client-4.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security net python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauth2client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/oauth2client
COMMENT=	Python library for accessing resources protected by OAuth 2.0
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules-[0-9]*:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
