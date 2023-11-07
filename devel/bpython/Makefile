# $NetBSD: Makefile,v 1.41 2023/11/07 22:37:57 wiz Exp $

DISTNAME=	bpython-0.24
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	https://bpython-interpreter.org/releases/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://bpython-interpreter.org/
COMMENT=	Fancy interface to the Python interpreter
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-curtsies>=0.4.0:../../devel/py-curtsies
DEPENDS+=	${PYPKGPREFIX}-cwcwidth-[0-9]*:../../devel/py-cwcwidth
DEPENDS+=	${PYPKGPREFIX}-greenlet-[0-9]*:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
