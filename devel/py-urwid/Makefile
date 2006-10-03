# $NetBSD: Makefile,v 1.5 2006/10/03 17:42:32 minskim Exp $

DISTNAME=	urwid-0.8.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://excess.org/urwid/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://excess.org/urwid/
COMMENT=	Curses-based Python user interface library

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
