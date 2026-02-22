# $NetBSD: Makefile,v 1.2 2026/02/22 13:01:06 wiz Exp $

DISTNAME=	lark-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lark-parser/lark/
COMMENT=	Parsing toolkit for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

CONFLICTS=	py[0-9]*-lark-parser-[0-9]*

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
