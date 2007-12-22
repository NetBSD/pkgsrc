# $NetBSD: Makefile,v 1.8 2007/12/22 00:18:08 joerg Exp $

DISTNAME=	urwid-0.9.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://excess.org/urwid/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://excess.org/urwid/
COMMENT=	Curses-based Python user interface library

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24
REPLACE_PYTHON=	*.py */*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
