# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 00:00:51 minskim Exp $

DISTNAME=	urwid-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://excess.org/urwid/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://excess.org/urwid/
COMMENT=	Curses-based Python user interface library

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	20 15

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
