# $NetBSD: Makefile,v 1.1 2017/07/20 17:20:57 adam Exp $

DISTNAME=	termstyle-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/termstyle/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/gfxmonk/termstyle
COMMENT=	Console colouring for python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON=	termstyle.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
