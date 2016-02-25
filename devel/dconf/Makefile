# $NetBSD: Makefile,v 1.29 2016/02/25 12:12:47 jperkin Exp $

PKGREVISION= 3
.include "Makefile.common"

CONFIGURE_ARGS+= --disable-editor

PKGCONFIG_OVERRIDE+=	client/dconf.pc.in dbus-1/dconf-dbus-1.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

SUBST_CLASSES.Darwin+=	libname
SUBST_STAGE.libname=	pre-configure
SUBST_FILES.libname=	client/Makefile.in dbus-1/Makefile.in
SUBST_FILES.libname+=	gsettings/Makefile.in
SUBST_SED.libname=	-e "s|-Wl,-soname=|-install_name ${PREFIX}/lib/|g"
SUBST_SED.libname+=	-e "/^libdconfsettings_so_LDFLAGS/s,$$, -install_name ${PREFIX}/lib/gio/modules/libdconfsettings.so,g"

BUILD_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

BUILDLINK_DEPMETHOD.vala= build
BUILDLINK_API_DEPENDS.vala+=	vala>=0.18.0
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.39.1
.include "../../devel/glib2/modules.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
