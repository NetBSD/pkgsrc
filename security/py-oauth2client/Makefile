# $NetBSD: Makefile,v 1.4 2016/03/03 12:59:55 wiz Exp $

DISTNAME=	oauth2client-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security net python
MASTER_SITES=	-https://github.com/google/oauth2client/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/oauth2client
COMMENT=	Python library for accessing resources protected by OAuth 2.0
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules-[0-9]*:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

REPLACE_PYTHON+=		oauth2client/util.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
