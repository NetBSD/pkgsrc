# $NetBSD: Makefile,v 1.28 2020/09/29 17:04:15 adam Exp $

DISTNAME=	urwid-2.1.2
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
