# $NetBSD: Makefile,v 1.13 2020/03/04 18:24:55 adam Exp $

DISTNAME=	pycparser-2.20
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eliben/pycparser
COMMENT=	C parser in Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
