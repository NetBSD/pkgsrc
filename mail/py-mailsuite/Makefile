# $NetBSD: Makefile,v 1.4 2023/10/28 19:57:10 wiz Exp $

DISTNAME=	mailsuite-1.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailsuite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seanthegeek/mailsuite/
COMMENT=	Python package for retrieving, parsing, and sending emails
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expiringdict-[0-9]*:../../devel/py-expiringdict
DEPENDS+=	${PYPKGPREFIX}-html2text>=2020.1.16:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-imapclient>=2.1.0:../../mail/py-imapclient
DEPENDS+=	${PYPKGPREFIX}-mail-parser>=3.14.0:../../mail/py-mail-parser
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20190812:../../www/py-publicsuffix2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
