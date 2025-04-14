# $NetBSD: Makefile,v 1.8 2025/04/14 09:56:26 adam Exp $

DISTNAME=	IMAPClient-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IMAPClient/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mjs/imapclient
COMMENT=	Convience IMAP client for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
