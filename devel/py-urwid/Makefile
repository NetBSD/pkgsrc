# $NetBSD: Makefile,v 1.6 2006/10/26 18:52:20 tonio Exp $

DISTNAME=	urwid-0.9.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://excess.org/urwid/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://excess.org/urwid/
COMMENT=	Curses-based Python user interface library

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
