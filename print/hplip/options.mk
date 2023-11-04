# $NetBSD: options.mk,v 1.22 2023/11/04 14:22:03 wiz Exp $
#
# HPLIP dependencies are detailed in the following page:
# http://hplipopensource.com/hplip-web/install/manual/distros/other.html

PKG_OPTIONS_VAR=	PKG_OPTIONS.hplip
PKG_SUPPORTED_OPTIONS=	fax sane # qt5
PKG_SUGGESTED_OPTIONS=	fax

.include "../../mk/bsd.options.mk"

# NB the qt5 option results in components that don't entirely function
# correctly, at least on NetBSD. This needs more work.
#.if !empty(PKG_OPTIONS:Mqt5)
#PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pyphen
#CONFIGURE_ARGS+=		--enable-gui-build
#CONFIGURE_ARGS+=		--enable-policykit
#EGFILES+=			dbus-1/system.d/com.hp.hplip.conf
#MAKE_DIRS+=			${PKG_SYSCONFDIR}/dbus-1/system.d
#.include "../../security/policykit/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#DEPENDS+=			${PYPKGPREFIX}-notify2-[0-9]*:../../sysutils/py-notify2
#PLIST_SRC+=			PLIST.qt5
#CONFIGURE_ARGS+=		--disable-qt4
#CONFIGURE_ARGS+=		--enable-qt5
#.include "../../x11/py-qt5/buildlink3.mk"
#.else
CONFIGURE_ARGS+=		--disable-policykit
CONFIGURE_ARGS+=		--disable-qt4
CONFIGURE_ARGS+=		--disable-qt5
CONFIGURE_ARGS+=		--disable-gui-build
#.endif

.if !empty(PKG_OPTIONS:Mfax)
PLIST_SRC+=		PLIST.fax
CONFIGURE_ARGS+=	--enable-fax-build
CONFIGURE_ARGS+=	--enable-dbus-build
EGFILES+=		cups/pstotiff.convs cups/pstotiff.types
MAKE_DIRS+=		${PKG_SYSCONFDIR}/cups
DEPENDS+=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus-build
CONFIGURE_ARGS+=	--disable-fax-build
.endif

.if !empty(PKG_OPTIONS:Msane)
PLIST_SRC+=		PLIST.scan
CONFIGURE_ARGS+=	--enable-scan-build
MESSAGE_SRC+=		MESSAGE.scan
MESSAGE_SUBST+=		EGDIR=${EGDIR}
PYTHON_VERSIONED_DEPENDENCIES=	Pillow
.include "../../lang/python/versioned_dependencies.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-scan-build
.endif
