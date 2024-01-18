# $NetBSD: Makefile,v 1.4 2024/01/18 15:59:37 adam Exp $

DISTNAME=	IMAPClient-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IMAPClient/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mjs/imapclient
COMMENT=	Convience IMAP client for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
