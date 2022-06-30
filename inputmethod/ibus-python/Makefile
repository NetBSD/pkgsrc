# $NetBSD: Makefile,v 1.25 2022/06/30 11:18:31 nia Exp $

PKGREVISION= 1
.include "../../inputmethod/ibus/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/ibus/ibus-python/}

COMMENT=	Python library for Intelligent Input Bus
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config intltool msgfmt gmake
GNU_CONFIGURE=		yes

DEPENDS+=	ibus>=${PKGVERSION_NOREV}:../../inputmethod/ibus
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject32
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

PKGCONFIG_OVERRIDE+=	ibus-1.0.pc.in

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-gtk3
CONFIGURE_ARGS+=	--disable-xim
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libnotify
CONFIGURE_ARGS+=	--disable-engine
CONFIGURE_ARGS+=	--disable-surround-text
CONFIGURE_ARGS+=	--disable-emoji-dict
CONFIGURE_ARGS+=	--disable-unicode-dict
CONFIGURE_ARGS+=	--disable-systemd-services

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.1.[0-9]*)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
.endif

NO_BUILD=	yes
INSTALL_DIRS=	bindings ibus

CONFIGURE_ARGS+=	--disable-dconf
CONFIGURE_ARGS+=	--enable-python-library
CONFIGURE_ENV+=		PYTHON2=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.83.0
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
