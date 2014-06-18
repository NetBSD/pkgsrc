# $NetBSD: options.mk,v 1.25 2014/06/18 09:26:10 wiz Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.openoffice3
PKG_SUPPORTED_OPTIONS=		cups gnome gtk2 kde ooo-external-libwpd xulrunner
# The list from completelangiso in solenv/inc/postset.mk.
OO_SUPPORTED_LANGUAGES=		af ar as-IN be-BY bg br brx bn bn-BD bn-IN bs \
				by ca cs cy da de dgo dz el en-GB en-US en-ZA \
				eo es et eu fa fi fr ga gd gl gu gu-IN he     \
				hi-IN hr hu it ja ka kk km kn kn-IN ko kok ks \
				ku lo lt lv mai mk mn mni ms ml-IN mr-IN my   \
				ne nb nl nn nr ns oc or-IN pa-IN pl pt pt-BR  \
				ru rw sat sa-IN sc sd sk sl sh sr ss st sv sw \
				sw-TZ te-IN ti-ER ta-IN th tn tr ts tg ur-IN  \
				uk uz ve vi xh zh-CN zh-TW zu all
.for l in ${OO_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=		lang-${l}
.endfor
PKG_SUGGESTED_OPTIONS=		gtk2 lang-en-US xulrunner
PKG_OPTIONS_LEGACY_OPTS+=	gnome-vfs:gnome

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
PKG_SUPPORTED_OPTIONS+=		java
.endif

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mlang-all)
OO_LANGS=	ALL
OO_BASELANG=	en-US
OO_LANGPACKS=	${OO_SUPPORTED_LANGUAGES:S/en-US//1:S/all//1}
.else
.  for lang in ${PKG_OPTIONS:Mlang-*:S/lang-//g}
OO_LANGS+=	${lang}
OO_BASELANG?=	${lang}	# Get first one.
.  endfor
.endif
OO_LANGS?=	en-US
OO_BASELANG?=	en-US
OO_LANGPACKS?=	${OO_LANGS:S/${OO_BASELANG}//1}

.if !empty(PKG_OPTIONS:Mxulrunner)
CONFIGURE_ARGS+=	--with-system-mozilla=mozilla
.include "../../devel/nss/buildlink3.mk"
BUILDLINK_API_DEPENDS.xulrunner17+=	xulrunner17>=17.0.6nb1
.include "../../devel/xulrunner17/buildlink3.mk"
#
# OOo ships headers that are too old and conflict with xulrunner headers.
# Instead of patching everything to include external headers, we just
# Update what they have in the tree to match our xulrunner package.
#
.PHONY: copy-mozilla-headers
post-wrapper:	copy-mozilla-headers
copy-mozilla-headers:
	cp \
	  ${BUILDLINK_DIR}/include/xulrunner17/npapi.h \
	  ${WRKSRC}/np_sdk/mozsrc
.else
CONFIGURE_ARGS+=	--disable-mozilla
.endif

.if !empty(PKG_OPTIONS:Mooo-external-libwpd)
CONFIGURE_ARGS+=	--with-system-libwpd
.include "../../converters/libwpd/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcups)
CONFIGURE_ARGS+=	--enable-cups
.include "../../print/cups15/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

PLIST_VARS+=		gnome
.if !empty(PKG_OPTIONS:Mgnome)
PLIST.gnome=		yes
CONFIGURE_ARGS+=	--enable-gnome-vfs --enable-evolution2
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome-vfs --disable-evolution2 --disable-gconf
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-gtk
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA2=		yes
BUILD_DEPENDS+=		apache-ant>=1.7.0nb1:../../devel/apache-ant
CONFIGURE_ARGS+=	--with-java
# Extensions (MI)
#CONFIGURE_ARGS+=	--enable-report-builder
#CONFIGURE_ARGS+=	--enable-wiki-publisher

JAVA_LIB_ROOT=	${PKG_JAVA_HOME}/jre/lib/${MACHINE_ARCH}
LIB.jawt=	-L${JAVA_LIB_ROOT} ${COMPILER_RPATH_FLAG}${JAVA_LIB_ROOT}
LIB.awtlib=	-L${JAVA_LIB_ROOT} ${COMPILER_RPATH_FLAG}${JAVA_LIB_ROOT}

# -rpath is missing from wip/jdk15.
CONFIGURE_ENV+=	LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${JAVA_LIB_ROOT}:${JAVA_LIB_ROOT}/xawt"

CONFIGURE_ENV+=		JAVA_HOME=${PKG_JAVA_HOME:Q}
MAKE_ENV+=		JAVA_HOME=${PKG_JAVA_HOME:Q}

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

PLIST_VARS+=		kde
.if !empty(PKG_OPTIONS:Mkde)
PLIST.kde=		yes
CONFIGURE_ENV+=		KDEDIR=${BUILDLINK_PREFIX.kdelibs:Q}
CONFIGURE_ARGS+=	--enable-kde --enable-kdeab
.include "../../x11/kdelibs3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-kde --disable-kdeab
.endif
