# $NetBSD: options.mk,v 1.26 2009/09/10 00:27:08 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openoffice2
PKG_SUPPORTED_OPTIONS=		cups gnome gtk2 kde nas ooo-external-libwpd # xulrunner
# The list from completelangiso in solenv/inc/postset.mk.
OO_SUPPORTED_LANGUAGES=		af ar as-IN be-BY bg br bn bn-BD bn-IN bs ca \
				cs cy da de dz el en-GB en-US en-ZA eo es et \
				eu fa fi fr ga gl gu-IN he hi-IN hr hu it ja \
				ka km kn ko ku lo lt lv mk ms ml-IN mr-IN ne \
				nb nl nn nr ns oc or-IN pa-IN pl pt pt-BR ru \
				rw sk sl sh sr ss st sv sw sw-TZ te-IN ti-ER \
				ta-IN th tn tr ts tg ur-IN uk ve vi xh zh-CN \
				zh-TW zu all
.for l in ${OO_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=		lang-${l}
.endfor
PKG_SUGGESTED_OPTIONS=		gtk2 lang-en-US
PKG_OPTIONS_LEGACY_OPTS+=	gnome-vfs:gnome

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mlang-all)
OO_LANGS=	ALL
OO_BASELANG=	en-US
OO_LANGPACKS=	${OO_SUPPORTED_LANGUAGES:S/en-US//1:S/all//1}
.else
.  for lang in ${PKG_OPTIONS:Mlang-*:S/lang-//g}
OO_LANGS+=	${lang}
OO_BASELANG?=	${lang} # Get first one.
.  endfor
.endif
OO_LANGS?=	en-US
OO_BASELANG?=	en-US
OO_LANGPACKS?=	${OO_LANGS:S/${OO_BASELANG}//1}

.if !empty(PKG_OPTIONS:Mxulrunner)
CONFIGURE_ARGS+=	--with-system-mozilla=mozilla
.include "../../devel/xulrunner/buildlink3.mk"
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

PLIST_VARS+=		gnome
.if !empty(PKG_OPTIONS:Mgnome)
PLIST.gnome=		yes
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

PLIST_VARS+=		kde
.if !empty(PKG_OPTIONS:Mkde)
PLIST.kde=		yes
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
