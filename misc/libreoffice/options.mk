# $NetBSD: options.mk,v 1.21 2022/05/24 09:46:56 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libreoffice

PKG_SUPPORTED_OPTIONS=	java debug gtk3 cups ldap dbus
PKG_SUGGESTED_OPTIONS=	cups ldap dbus gtk3

.include "../../mk/bsd.prefs.mk"

# "checking the installed JDK... configure: error: JDK is too old, you need at least 9"
#
# Only enable Java on platforms where OpenJDK>=9 is the default,
# see mk/java-vm.mk
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || \
    !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
PKG_SUGGESTED_OPTIONS+=	java
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ldap gtk3

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA=		yes
USE_JAVA2=		9
.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant
CONFIGURE_ARGS+=	--with-ant-home=${PREFIX}

DEPENDS+=		hsqldb18-[0-9]*:../../databases/hsqldb18
CONFIGURE_ARGS+=	--with-hsqldb-jar=${PREFIX}/lib/java/hsqldb18/hsqldb.jar
CONFIGURE_ARGS+=	--enable-ext-wiki-publisher \
			--with-java \
			--with-jdk-home=${PKG_JAVA_HOME} \
			--without-system-beanshell \
			--enable-scripting-beanshell \
			--with-system-hsqldb \
			--without-system-jfreereport
CONFIGURE_ARGS+=	--with-export-validation
PLIST_SRC=		${PLIST_SRC_DFLT:Q} ${PKGDIR}/PLIST.java
.else
CONFIGURE_ARGS+=	--without-java
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
PLIST_SRC=		${PLIST_SRC_DFLT:Q} ${PKGDIR}/PLIST.debug
.else
CONFIGURE_ARGS+=	--enable-release-build
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gtk3
PLIST.gtk3=		yes
.else
CONFIGURE_ARGS+=	--disable-gtk3
.endif

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/libcups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ldap
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif
