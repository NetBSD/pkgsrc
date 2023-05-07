# $NetBSD: Makefile,v 1.1 2023/05/07 20:52:58 markd Exp $

DISTNAME=	authheaders-0.15.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/authheaders/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ValiMail/authentication-headers/
COMMENT=	Library for email authentication header verification and generation
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-dkim>=0.7.1:../../mail/py-dkim
DEPENDS+=	${PYPKGPREFIX}-authres>=1.2.0:../../mail/py-authres
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2-[0-9]*:../../www/py-publicsuffix2
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
