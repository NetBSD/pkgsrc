# $NetBSD: Makefile,v 1.4 2024/11/11 07:28:29 wiz Exp $

DISTNAME=	urwidgets-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwidgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnonymouX47/urwidgets
COMMENT=	Collection of widgets for urwid
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.1:../../devel/py-urwid

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
