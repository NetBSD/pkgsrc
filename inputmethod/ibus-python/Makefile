# $NetBSD: Makefile,v 1.9 2016/03/02 22:59:00 ryoon Exp $

.include "../../inputmethod/ibus/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/ibus/ibus-python/}

COMMENT=	Python library for Intelligent Input Bus
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake
USE_LANGUAGES=	c c++
USE_PKGLOCALEDIR=	yes

DEPENDS+=		ibus>=${PKGVERSION_NOREV}:../../inputmethod/ibus
DEPENDS+=		${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

PKGCONFIG_OVERRIDE+=	ibus-1.0.pc.in

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-gtk3
CONFIGURE_ARGS+=	--disable-xim
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libnotify
CONFIGURE_ARGS+=	--disable-engine
CONFIGURE_ARGS+=	--disable-surround-text

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.1.[0-9]*)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
.endif

NO_BUILD=	yes
INSTALL_DIRS=	bindings ibus

CONFIGURE_ARGS+=		--disable-dconf
CONFIGURE_ARGS+=		--disable-gconf
CONFIGURE_ARGS+=		--enable-python-library
CONFIGURE_ENV+=			PYTHON2=${PYTHONBIN}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-gtk2, py-gobject3

.include "../../devel/py-gobject3/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.83.0
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
