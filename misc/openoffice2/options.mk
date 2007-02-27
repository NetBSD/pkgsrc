# $NetBSD: options.mk,v 1.1.1.1 2007/02/27 11:55:57 hira Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openoffice2
PKG_SUPPORTED_OPTIONS=		cups gtk2 gnome-vfs2 # kde
PKG_OPTIONS_REQUIRED_GROUPS=	browser lang
PKG_OPTIONS_GROUP.browser=	firefox firefox-gtk1 seamonkey seamonkey-gtk1
OO_SUPPORTED_LANGUAGES=		en-US af as-IN be-BY bg br bs ca cs cy da de \
				el en-GB en-ZA eo es et fa fi fr ga gu-IN he \
				hi-IN hr hu it ja ka km ko ku lt mk ml-IN    \
				mr-IN nb ne nl nn nr ns or-IN pa-IN pl pt    \
				pt-BR ru rw sh-YU sk sl sr-CS ss st sv sw-TZ \
				ta-IN te-IN tg th ti-ER tn tr ts uk ur-IN ve \
				vi xh zh-CN zh-TW zu
.for l in ${OO_SUPPORTED_LANGUAGES}
PKG_OPTIONS_GROUP.lang+=	lang-${l}
.endfor
PKG_SUGGESTED_OPTIONS=		lang-en-US firefox

.include "../../mk/bsd.options.mk"

OPENOFFICE_LANGUAGE=		${PKG_OPTIONS:Mlang-*:S/^lang-//1}

.if !empty(PKG_OPTIONS:Mfirefox)
.include "../../www/firefox/buildlink3.mk"
CONFIGURE_ARGS+=	--with-system-mozilla --with-firefox
.endif

.if !empty(PKG_OPTIONS:Mfirefox-gtk1)
.include "../../www/firefox-gtk1/buildlink3.mk"
CONFIGURE_ARGS+=	--with-system-mozilla --with-firefox
.endif

.if !empty(PKG_OPTIONS:Mseamonkey)
.include "../../www/seamonkey/buildlink3.mk"
CONFIGURE_ARGS+=	--with-system-mozilla
.endif

.if !empty(PKG_OPTIONS:Mseamonkey-gtk1)
.include "../../www/seamonkey-gtk1/buildlink3.mk"
CONFIGURE_ARGS+=	--with-system-mozilla
.endif

# Not tested.
.if !empty(PKG_OPTIONS.Mcups)
.include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mgnome-vfs2)
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gnome-vfs
.else
CONFIGURE_ARGS+=	--disable-gnome-vfs
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

# XXX: Not yet.
.if !empty(PKG_OPTIONS:Mkde)
.include "../../x11/kdelibs3/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kde
.else
CONFIGURE_ARGS+=	--disable-kde
.endif
