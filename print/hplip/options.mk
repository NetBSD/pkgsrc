# $NetBSD: options.mk,v 1.1.1.1 2012/05/18 03:03:20 schnoebe Exp $
#
# HPLIP dependencies are detailed in the following page:
# http://hplipopensource.com/hplip-web/install/manual/distros/other.html
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hplip
PKG_SUPPORTED_OPTIONS=	fax sane qt
PKG_SUGGESTED_OPTIONS=	fax sane
PKG_OPTIONS_LEGACY_OPTS+=	scan:sane
PKG_OPTIONS_LEGACY_OPTS+=	gui:qt

.include "../../mk/bsd.options.mk"

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
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-scan-build
.endif

.if !empty(PKG_OPTIONS:Mqt)
PLIST_SRC+=		PLIST.gui
CONFIGURE_ARGS+=	--enable-gui-build
CONFIGURE_ARGS+=	--enable-qt4
CONFIGURE_ARGS+=	--enable-policykit
EGFILES+=		dbus-1/system.d/com.hp.hplip.conf
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dbus-1/system.d
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/py-notify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-policykit
CONFIGURE_ARGS+=	--disable-qt4
CONFIGURE_ARGS+=	--disable-gui-build
.endif
