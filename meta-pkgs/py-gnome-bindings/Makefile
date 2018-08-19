# $NetBSD: Makefile,v 1.22 2018/08/19 20:16:40 wiz Exp $

DISTNAME=	${PYPKGPREFIX}-gnome-bindings-2.26.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Meta-package for Python bindings for the GNOME desktop

META_PACKAGE=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit, py-gnome2, py-gtk2

.include "../../lang/python/pyversion.mk"

# see http://ftp.gnome.org/pub/GNOME/bindings/2.26/2.26.2/sources/python/

DEPENDS+=	${PYPKGPREFIX}-gnome2>=2.26.1:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.16.1:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.14.1:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-ORBit>=2.14.3:../../net/py-ORBit

.include "../../mk/bsd.pkg.mk"
