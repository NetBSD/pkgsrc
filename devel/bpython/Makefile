# $NetBSD: Makefile,v 1.34 2022/06/30 11:18:11 nia Exp $

DISTNAME=	bpython-0.22.1
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	https://bpython-interpreter.org/releases/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://bpython-interpreter.org/
COMMENT=	Fancy interface to the Python interpreter
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-curtsies>=0.3.5:../../devel/py-curtsies
DEPENDS+=	${PYPKGPREFIX}-cwcwidth-[0-9]*:../../devel/py-cwcwidth
DEPENDS+=	${PYPKGPREFIX}-greenlet-[0-9]*:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-backports.cached-property-[0-9]*:../../devel/py-backports.cached-property
.endif

.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
