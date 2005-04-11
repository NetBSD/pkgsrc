# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:37 tv Exp $

DISTNAME=	urwid-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://excess.org/urwid/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://excess.org/urwid/
COMMENT=	Curses-based Python user interface library

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	20 15

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
