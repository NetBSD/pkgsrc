# $NetBSD: options.mk,v 1.5 2025/07/01 11:48:23 hauke Exp $
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
PKG_JVMS_ACCEPTED=	oracle-jdk21

PLIST.java=		yes
PUBLIC_BINS+=		dsmj

.include "../../mk/java-vm.mk"
.endif
