# $NetBSD: Makefile,v 1.5 2024/01/18 16:02:56 adam Exp $

DISTNAME=	mailsuite-1.9.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailsuite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seanthegeek/mailsuite
COMMENT=	Python package for retrieving, parsing, and sending emails
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dns>=2.0.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expiringdict>=1.2.2:../../devel/py-expiringdict
DEPENDS+=	${PYPKGPREFIX}-html2text>=2020.1.16:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-imapclient>=2.1.0:../../mail/py-imapclient
DEPENDS+=	${PYPKGPREFIX}-mail-parser>=3.14.0:../../mail/py-mail-parser
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20190812:../../www/py-publicsuffix2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
