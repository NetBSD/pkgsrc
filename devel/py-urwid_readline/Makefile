# $NetBSD: Makefile,v 1.1 2024/05/13 09:47:42 wiz Exp $

DISTNAME=	urwid_readline-0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwid_readline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rr-/urwid_readline
COMMENT=	Textbox edit widget for urwid that supports readline shortcuts
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-urwid>=0:../../devel/py-urwid

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
