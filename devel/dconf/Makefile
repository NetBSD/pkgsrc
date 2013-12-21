# $NetBSD: Makefile,v 1.20 2013/12/21 11:31:33 jperkin Exp $

.include "Makefile.common"

CONFIGURE_ARGS+= --disable-editor

PKGCONFIG_OVERRIDE+=	client/dconf.pc.in dbus-1/dconf-dbus-1.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-Wl,-soname=libdconf-dbus-1.so.0
BUILDLINK_TRANSFORM+=	rm:-Wl,-soname=libdconf.so.1
INSTALL_UNSTRIPPED=	yes
.endif

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala018/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.35.2
.include "../../devel/glib2/modules.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
