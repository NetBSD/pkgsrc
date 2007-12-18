# $NetBSD: options.mk,v 1.17 2007/12/18 22:24:29 hira Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openoffice2
PKG_SUPPORTED_OPTIONS=		cups gnome gtk2 kde nas ooo-external-libwpd
PKG_OPTIONS_OPTIONAL_GROUPS=	browser
PKG_OPTIONS_GROUP.browser=	firefox seamonkey # firefox-gtk1 seamonkey-gtk1
# The list from completelangiso in solenv/inc/postset.mk.
OO_SUPPORTED_LANGUAGES=		af ar as-IN be-BY bg br bn bn-BD bn-IN bs ca \
				cs cy da de dz el en-GB en-US en-ZA eo es et \
				eu fa fi fr ga gl gu-IN he hi-IN hr hu it ja \
				ka km kn-IN ko ku lo lt lv mk ms ml-IN mr-IN \
				ne nb nl nn nr ns or-IN pa-IN pl pt pt-BR ru \
				rw sk sl sh-YU sr-CS ss st sv sw sw-TZ sx    \
				te-IN ti-ER ta-IN th tn tr ts tg ur-IN uk ve \
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
CONFIGURE_ARGS+=	--with-system-mozilla=firefox
.include "../../www/firefox/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mseamonkey)
CONFIGURE_ARGS+=	--with-system-mozilla=seamonkey
.include "../../www/seamonkey/buildlink3.mk"
# The following browsers do not install *.pc files.
#.elif !empty(PKG_OPTIONS:Mfirefox-gtk1)
#CONFIGURE_ARGS+=	--with-system-mozilla=firefox
#.include "../../www/firefox-gtk1/buildlink3.mk"
#.elif !empty(PKG_OPTIONS:Mseamonkey-gtk1)
#CONFIGURE_ARGS+=	--with-system-mozilla=seamonkey
#.include "../../www/seamonkey-gtk1/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mozilla
.endif

.if !empty(PKG_OPTIONS:Mooo-external-libwpd)
CONFIGURE_ARGS+=	--with-system-libwpd
.include "../../converters/libwpd/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcups)
CONFIGURE_ARGS+=	--enable-cups
.include "../../print/cups/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnome-vfs --enable-evolution2
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome-vfs --disable-evolution2
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-gtk
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

.if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=	--with-system-nas
# Build error with nas<=1.9.
BUILDLINK_API_DEPENDS.nas+=	nas>=1.9nb1
.include "../../audio/nas/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-nas
.endif
