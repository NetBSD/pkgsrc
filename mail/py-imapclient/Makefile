# $NetBSD: Makefile,v 1.9 2026/01/20 19:54:06 adam Exp $

DISTNAME=	imapclient-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IMAPClient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mjs/imapclient
COMMENT=	Convience IMAP client for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
