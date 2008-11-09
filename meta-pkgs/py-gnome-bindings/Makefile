# $NetBSD: Makefile,v 1.1.1.1 2008/11/09 10:40:57 wiz Exp $

DISTNAME=	p5-gnome-bindings-2.24.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for Python bindings for the GNOME desktop

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"

# see http://ftp.gnome.org/pub/GNOME/bindings/2.24/2.24.1/sources/python/

DEPENDS+=	${PYPKGPREFIX}-gnome>=2.22.3:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.15.4:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.13.0:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-ORBit>=2.14.3:../../net/py-ORBit

.include "../../mk/bsd.pkg.mk"
