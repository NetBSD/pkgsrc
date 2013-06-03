# $NetBSD: Makefile,v 1.3 2013/06/03 10:04:43 wiz Exp $
#

DISTNAME=	bpython-0.12
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://bpython-interpreter.org/releases/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://bpython-interpreter.org/
COMMENT=	Fancy interface to the Python interpreter
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-urwid>=0.9.9.1:../../devel/py-urwid

PKG_OPTIONS_VAR=	PKG_OPTIONS.bpython
PKG_SUPPORTED_OPTIONS=  gtk
PKG_SUGGESTED_OPTIONS=  # empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.endif

.include "../../devel/py-readline/buildlink3.mk"
.include "../../devel/py-curses/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
