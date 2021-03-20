# $NetBSD: Makefile,v 1.28 2021/03/20 15:14:48 adam Exp $

DISTNAME=	bpython-0.21
CATEGORIES=	devel python
MASTER_SITES=	https://bpython-interpreter.org/releases/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://bpython-interpreter.org/
COMMENT=	Fancy interface to the Python interpreter
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-curtsies>=0.3.5:../../devel/py-curtsies
DEPENDS+=	${PYPKGPREFIX}-greenlet-[0-9]*:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
