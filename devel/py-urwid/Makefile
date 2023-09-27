# $NetBSD: Makefile,v 1.30 2023/09/27 10:03:00 adam Exp $

DISTNAME=	urwid-2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwid/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://urwid.org/
COMMENT=	Curses-based Python user interface library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
