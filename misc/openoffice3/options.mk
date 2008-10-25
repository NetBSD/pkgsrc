# $NetBSD: options.mk,v 1.10 2008/10/25 15:18:17 hira Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.openoffice3
PKG_SUPPORTED_OPTIONS=		cups gnome gtk2 java kde ooo-external-libwpd
PKG_OPTIONS_OPTIONAL_GROUPS=	browser
PKG_OPTIONS_GROUP.browser=	firefox firefox3 seamonkey
# The list from completelangiso in solenv/inc/postset.mk.
OO_SUPPORTED_LANGUAGES=		af ar as-IN be-BY bg br bn bn-BD bn-IN bs by \
				ca cs cy da de dz el en-GB en-US en-ZA eo es \
				et eu fa fi fr ga gd gl gu gu-IN he hi-IN hr \
				hu it ja ka km kn ko ku lo lt lv mk mn ms    \
				ml-IN mr-IN my ne nb nl nn nr ns oc or-IN    \
				pa-IN pl pt pt-BR ru rw sk sl sh sr ss st sv \
				sw sw-TZ te-IN ti-ER ta-IN th tn tr ts tg    \
				ur-IN uk uz ve vi xh zh-CN zh-TW zu all
.for l in ${OO_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=		lang-${l}
.endfor
PKG_SUGGESTED_OPTIONS=		firefox gtk2 lang-en-US
PKG_OPTIONS_LEGACY_OPTS+=	gnome-vfs:gnome

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mlang-all)
OO_LANGS=	ALL
OO_BASELANG=	en-US
OO_LANGPACKS=	${OO_SUPPORTED_LANGUAGES:S/en-US//1:S/all//1}
.else
.  for _l in ${PKG_OPTIONS:Mlang-*:S/lang-//g}
OO_LANGS+=	${_l}
OO_BASELANG?=	${_l}	# Get first one.
.  endfor
.endif
OO_LANGS?=	en-US
OO_BASELANG?=	en-US
OO_LANGPACKS?=	${OO_LANGS:S/${OO_BASELANG}//1}

SUBST_CLASSES+=		instset
SUBST_STAGE.instset=	post-patch
SUBST_MESSAGE.instset=	Reduce OOo install sets.
SUBST_FILES.instset=	instsetoo_native/util/makefile.mk
SUBST_SED.instset+=	-e 's,@BASELANG@,${OO_BASELANG},g'
SUBST_SED.instset+=	-e 's,@LANGPACKS@,${OO_LANGPACKS},g'

.if !empty(PKG_OPTIONS:Mfirefox)
MOZ_FLAVOUR=		firefox
CONFIGURE_ARGS+=	--with-system-mozilla=firefox
.include "../../www/firefox/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mfirefox3)
MOZ_FLAVOUR=		firefox3
CONFIGURE_ARGS+=	--with-system-mozilla=firefox3
.include "../../www/firefox3/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mseamonkey)
MOZ_FLAVOUR=		seamonkey
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
MOZ_FLAVOUR=
CONFIGURE_ARGS+=	--disable-mozilla
.endif

SUBST_CLASSES+=		browser
SUBST_STAGE.browser=	post-patch
SUBST_MESSAGE.browser=	Adding MOZ_FLAVOUR
SUBST_FILES.browser=	shell/source/unix/misc/open-url.sh
SUBST_SED.browser+=	-e 's,@MOZ_FLAVOUR@,${MOZ_FLAVOUR},g'

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

PLIST_VARS+=		gtk2
.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.gtk2=		yes
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA2=		yes
DEPENDS+=		apache-ant>=1.7.0:../../devel/apache-ant
CONFIGURE_ARGS+=	--with-java
# Extensions (MI)
#CONFIGURE_ARGS+=	--enable-report-builder
#CONFIGURE_ARGS+=	--enable-wiki-publisher

JAVA_LIB_ROOT=	${PKG_JAVA_HOME}/jre/lib/${MACHINE_ARCH}
LIB.jawt=	-L${JAVA_LIB_ROOT} ${COMPILER_RPATH_FLAG}${JAVA_LIB_ROOT}
LIB.awtlib=	-L${JAVA_LIB_ROOT} ${COMPILER_RPATH_FLAG}${JAVA_LIB_ROOT}

# -rpath is missing from wip/jdk15.
CONFIGURE_ENV+=	LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${JAVA_LIB_ROOT}:${JAVA_LIB_ROOT}/xawt"

# XXX: devel/apache-ant doesn't setup ${PREFIX}/bin/java.
CONFIGURE_ENV+=		JAVACMD="${PKG_JAVA_HOME}/bin/java"
MAKE_ENV+=		JAVACMD="${PKG_JAVA_HOME}/bin/java"

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--without-java
PKG_JAVA_HOME=
LIB.jawt=
LIB.awtlib=
.endif

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-patch
SUBST_MESSAGE.java=	Adding JAVA_HOME
SUBST_FILES.java=	desktop/scripts/soffice.sh
SUBST_FILES.java+=	desktop/scripts/unopkg.sh
SUBST_FILES.java+=	padmin/source/spadmin.sh
SUBST_SED.java+=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.java+=	-e 's,@JAVA_MAWT_DIR@,${JAVA_LIB_ROOT}/xawt,g'
SUBST_SED.lib+=		-e 's|@LIB_jawt@|${LIB.jawt}|g'
SUBST_SED.lib+=		-e 's|@LIB_awtlib@|${LIB.awtlib}|g'

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ENV+=		KDEDIR=${BUILDLINK_PREFIX.kdelibs:Q}
CONFIGURE_ARGS+=	--enable-kde --enable-kdeab
.include "../../x11/kdelibs3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-kde --disable-kdeab
.endif
