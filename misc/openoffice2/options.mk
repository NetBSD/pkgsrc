# $NetBSD: options.mk,v 1.9 2007/04/21 05:40:27 hira Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openoffice2
PKG_SUPPORTED_OPTIONS=		cups gnome gtk2 kde
PKG_OPTIONS_REQUIRED_GROUPS=	browser
PKG_OPTIONS_GROUP.browser=	firefox # seamonkey firefox-gtk1 seamonkey-gtk1
OO_SUPPORTED_LANGUAGES=		en-US af as-IN be-BY bg br bs ca cs cy da de \
				el en-GB en-ZA eo es et fa fi fr ga gu-IN he \
				hi-IN hr hu it ja ka km ko ku lt mk ml-IN    \
				mr-IN nb ne nl nn nr ns or-IN pa-IN pl pt    \
				pt-BR ru rw sh-YU sk sl sr-CS ss st sv sw-TZ \
				ta-IN te-IN tg th ti-ER tn tr ts uk ur-IN ve \
				vi xh zh-CN zh-TW zu
.for l in ${OO_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=		lang-${l}
.endfor
PKG_SUGGESTED_OPTIONS=		gtk2 lang-en-US firefox
PKG_OPTIONS_LEGACY_OPTS+=	gnome-vfs:gnome

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.for l in ${PKG_OPTIONS:Mlang-*}
OO_LANGS+=	${l:S/^lang-//1}
.endfor
OO_LANGS?=	en-US

.if !empty(PKG_OPTIONS:Mfirefox)
CONFIGURE_ARGS+=	--with-system-mozilla --with-firefox
.include "../../www/firefox/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfirefox-gtk1)
CONFIGURE_ARGS+=	--with-system-mozilla --with-firefox
.include "../../www/firefox-gtk1/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mseamonkey)
CONFIGURE_ARGS+=	--with-system-mozilla
.include "../../www/seamonkey/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mseamonkey-gtk1)
CONFIGURE_ARGS+=	--with-system-mozilla
.include "../../www/seamonkey-gtk1/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcups)
CONFIGURE_ARGS+=	--enable-cups
.include "../../print/cups/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome-vfs --enable-evolution2
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome-vfs --disable-evolution2
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-gtk
# *.pc files are needed with NetBSD using native XFree86.
.  if ${OPSYS} == "NetBSD" && defined(X11_TYPE) && !empty(X11_TYPE:Mnative)
USE_BUILTIN.Xfixes=	no
USE_BUILTIN.Xrandr=	no
USE_BUILTIN.Xrender=	no
.  endif
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ENV+=		KDEDIR=${BUILDLINK_PREFIX.kdelibs:Q}
CONFIGURE_ARGS+=	--enable-kde --enable-kdeab
.include "../../x11/kdelibs3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-kde --disable-kdeab
.endif
