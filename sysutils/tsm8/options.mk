# $NetBSD: options.mk,v 1.1 2018/10/17 13:54:39 hauke Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.tsm
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	java

.if !empty(PKG_OPTIONS:Mjava)

USE_TOOLS+=		bash:run

USE_JAVA=		run
USE_JAVA2=		yes
# We need a Linux jvm
PKG_JVMS_ACCEPTED=	sun-jdk7 oracle-jdk8

PLIST.java=		yes
PUBLIC_BINS+=		dsmj

.include "../../mk/java-vm.mk"
.endif
