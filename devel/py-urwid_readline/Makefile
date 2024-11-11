# $NetBSD: Makefile,v 1.3 2024/11/11 07:28:29 wiz Exp $

DISTNAME=	urwid_readline-0.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwid_readline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rr-/urwid_readline
COMMENT=	Textbox edit widget for urwid that supports readline shortcuts
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-urwid>=0:../../devel/py-urwid

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
