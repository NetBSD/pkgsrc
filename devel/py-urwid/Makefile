# $NetBSD: Makefile,v 1.3 2006/02/05 23:08:52 joerg Exp $

DISTNAME=	urwid-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
