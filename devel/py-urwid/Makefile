# $NetBSD: Makefile,v 1.24 2018/01/20 21:16:27 adam Exp $

DISTNAME=	urwid-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwid/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://urwid.org/
COMMENT=	Curses-based Python user interface library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
