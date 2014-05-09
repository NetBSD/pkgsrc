# $NetBSD: Makefile,v 1.23 2014/05/09 07:36:58 wiz Exp $

DISTNAME=	accerciser-1.12.1
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/accerciser/1.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Interactive Python accessibility explorer for the GNOME desktop
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gnome2-desktop-[0-9]*:../../x11/py-gnome2-desktop
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.8:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-at-spi>=1.23.4:../../devel/py-at-spi
DEPENDS+=	${PYPKGPREFIX}-ipython<0.11:../../devel/py-ipython010

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-ORBit via py-gnome2, py-ipython, py-gtk2

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PY_PATCHPLIST=		yes
REPLACE_PYTHON=		plugins/ipython_view.py
REPLACE_PYTHON+=	src/accerciser.in

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
