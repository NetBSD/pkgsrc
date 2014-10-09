# $NetBSD: Makefile,v 1.20 2014/10/09 11:57:36 adam Exp $

DISTNAME=	urwid-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/u/urwid/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://urwid.org/
COMMENT=	Curses-based Python user interface library
LICENSE=	gnu-lgpl-v2.1 # or later

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

REPLACE_PYTHON=	*.py */*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
