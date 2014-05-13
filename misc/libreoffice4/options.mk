# $NetBSD: options.mk,v 1.3 2014/05/13 18:36:02 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libreoffice4
PKG_SUPPORTED_OPTIONS=	java debug

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS=	java
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	java

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA=		yes
USE_JAVA2=		yes
BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant
FIND_PREFIX:=		ANTDIR=apache-ant
DEPENDS+=	hsqldb18-[0-9]*:../../databases/hsqldb18
FIND_PREFIX:=		HSQLDB_SYSDIR=hsqldb18
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--enable-ext-wiki-publisher \
			--with-java \
			--with-jdk-home=${PKG_JAVA_HOME} \
			--with-ant-home=${ANTDIR} \
			--enable-scripting-beanshell \
			--enable-scripting-javascript \
			--with-system-hsqldb \
			--with-hsqldb-jar=${HSQLDB_SYSDIR}/lib/java/hsqldb18/hsqldb.jar
.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
PLIST_SRC+=		${PLIST_SRC_DFLT:Q} PLIST.java
PLIST.java=		yes
.else
CONFIGURE_ARGS+=	--without-java
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--enable-selective-debuginfo="all"
.else
CONFIGURE_ARGS+=	--enable-release-build
.endif
