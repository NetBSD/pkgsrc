# $NetBSD: Makefile,v 1.4 2022/01/15 20:01:37 js Exp $

DISTNAME=	Telethon-1.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Telethon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LonamiWebs/Telethon
COMMENT=	Full-featured Telegram client library for Python 3
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
