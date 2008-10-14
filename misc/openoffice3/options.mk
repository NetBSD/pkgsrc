# $NetBSD: options.mk,v 1.1.1.1 2008/10/14 11:02:24 hira Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openoffice3
PKG_SUPPORTED_OPTIONS=		cups gnome gtk2 java kde ooo-external-libwpd
PKG_OPTIONS_OPTIONAL_GROUPS=	browser
PKG_OPTIONS_GROUP.browser=	firefox firefox3 seamonkey
# The list from completelangiso in solenv/inc/postset.mk.
OO_SUPPORTED_LANGUAGES=		af ar as-IN be-BY bg br bn bn-BD bn-IN bs ca \
				cs cy da de dz el en-GB en-US en-ZA eo es et \
				eu fa fi fr ga gl gu-IN he hi-IN hr hu it ja \
				ka km kn ko ku lo lt lv mk ms ml-IN mr-IN ne \
				nb nl nn nr ns oc or-IN pa-IN pl pt pt-BR ru \
				rw sk sl sh sr ss st sv sw sw-TZ te-IN ti-ER \
				ta-IN th tn tr ts tg ur-IN uk uz ve vi xh    \
				zh-CN zh-TW zu
.for l in ${OO_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=		lang-${l}
.endfor
PKG_SUGGESTED_OPTIONS=		firefox gtk2 lang-en-US
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
.elif !empty(PKG_OPTIONS:Mfirefox3)
CONFIGURE_ARGS+=	--with-system-mozilla=firefox3
.include "../../www/firefox3/buildlink3.mk"
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

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA2=		yes
DEPENDS+=		apache-ant>=1.7.0:../../devel/apache-ant
CONFIGURE_ARGS+=	--with-java --disable-mediawiki

# -rpath is missing for -lmawt.  Please fix wip/jdk15.
JAVA_XAWT_DIR=		${PKG_JAVA_HOME}/jre/lib/${MACHINE_ARCH}/xawt
CONFIGURE_ENV+=		LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${JAVA_XAWT_DIR}"

# I can't find wrapper of Java (${PREFIX}/bin/java).
# It exists in ${PREFIX}/bin/ant.
CONFIGURE_ENV+=		JAVACMD="${PKG_JAVA_HOME}/bin/java"
MAKE_ENV+=		JAVACMD="${PKG_JAVA_HOME}/bin/java"

# XXX
RFLAG_AWTLIB=		-L${PKG_JAVA_HOME}/jre/lib/${MACHINE_ARCH} -Wl,-R${PKG_JAVA_HOME}/jre/lib/${MACHINE_ARCH}

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--without-java
PKG_JAVA_HOME=
JAVA_XAWT_DIR=
RFLAG_AWTLIB=
.endif

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-patch
SUBST_MESSAGE.java=	Adding JAVA_HOME
SUBST_FILES.java=	desktop/scripts/soffice.sh
SUBST_FILES.java+=	desktop/scripts/unopkg.sh
SUBST_FILES.java+=	padmin/source/spadmin.sh
SUBST_SED.java+=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'
SUBST_SED.java+=	-e 's,@JAVA_XAWT_DIR@,${JAVA_XAWT_DIR},g'
SUBST_SED.lib+=		-e 's|@RFLAG_AWTLIB@|${RFLAG_AWTLIB}|g'

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ENV+=		KDEDIR=${BUILDLINK_PREFIX.kdelibs:Q}
CONFIGURE_ARGS+=	--enable-kde --enable-kdeab
.include "../../x11/kdelibs3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-kde --disable-kdeab
.endif
