# $NetBSD: Makefile,v 1.23 2017/05/25 06:38:44 adam Exp $

DISTNAME=	bpython-0.16
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://bpython-interpreter.org/releases/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://bpython-interpreter.org/
COMMENT=	Fancy interface to the Python interpreter
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-curtsies>=0.1.18:../../devel/py-curtsies
DEPENDS+=	${PYPKGPREFIX}-greenlet-[0-9]*:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-urwid>=0.9.9.1:../../devel/py-urwid

# to generate man pages
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
