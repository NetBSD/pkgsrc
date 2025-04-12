# $NetBSD: Makefile,v 1.5 2025/04/12 21:37:07 adam Exp $

DISTNAME=	urwidgets-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwidgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnonymouX47/urwidgets
COMMENT=	Collection of widgets for urwid
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.1:../../devel/py-urwid

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
