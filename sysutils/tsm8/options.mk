# $NetBSD: options.mk,v 1.4 2025/04/02 12:19:02 wiz Exp $
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
PKG_JVMS_ACCEPTED=	oracle-jdk17

PLIST.java=		yes
PUBLIC_BINS+=		dsmj

.include "../../mk/java-vm.mk"
.endif
