# $NetBSD: Makefile,v 1.1 2020/07/27 20:11:44 adam Exp $

DISTNAME=	py3c-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
# PyPI version does not have anything useful as of 1.2
#MASTER_SITES=	${MASTER_SITE_PYPI:=p/py3c/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=encukou/}
GITHUB_PROJECT=	py3c
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encukou/py3c
COMMENT=	Python compatibility headers
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
