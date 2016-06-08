# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:21 wiz Exp $

DISTNAME=	python-termstyle-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-termstyle/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://gfxmonk.net/dist/0install/python-termstyle.xml
COMMENT=	Console colouring for python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON=	termstyle.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
