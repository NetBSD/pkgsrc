# $NetBSD: Makefile,v 1.12 2014/05/09 07:36:58 wiz Exp $

DISTNAME=	bpython-0.12
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://bpython-interpreter.org/releases/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://bpython-interpreter.org/
COMMENT=	Fancy interface to the Python interpreter
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-urwid>=0.9.9.1:../../devel/py-urwid

PKG_OPTIONS_VAR=	PKG_OPTIONS.bpython
PKG_SUPPORTED_OPTIONS=  gtk
PKG_SUGGESTED_OPTIONS=  # empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2
.endif

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
