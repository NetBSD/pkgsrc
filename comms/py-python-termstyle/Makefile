# $NetBSD: Makefile,v 1.1 2014/12/06 03:19:01 rodent Exp $

DISTNAME=	python-termstyle-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-termstyle/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://gfxmonk.net/dist/0install/python-termstyle.xml
COMMENT=	Console colouring for python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON=	termstyle.py
EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
