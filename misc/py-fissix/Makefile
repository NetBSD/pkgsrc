# $NetBSD: Makefile,v 1.1 2026/11/24 17:19:26 adam Exp $

DISTNAME=	fissix-26.10.29
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fissix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/amyreese/fissix
COMMENT=	Monkeypatches to override default behavior of lib2to3
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.12.0:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.4.0:../../misc/py-platformdirs

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	fissix/pgen2/token.py
REPLACE_PYTHON+=	fissix/tests/data/different_encoding.py
REPLACE_PYTHON+=	fissix/tests/data/false_encoding.py
REPLACE_PYTHON+=	fissix/tests/pytree_idempotency.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
