# $NetBSD: Makefile,v 1.5 2022/01/14 09:28:40 wiz Exp $

DISTNAME=	pbkdf2-1.3
PKGNAME=	${PYPKGPREFIX}-pbkdf2-1.3
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbkdf2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pbkdf2
COMMENT=	PKCS \#5 v2.0 PBKDF2 Module
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON=	pbkdf2.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
