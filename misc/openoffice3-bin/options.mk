# $NetBSD: options.mk,v 1.3 2010/09/13 22:32:02 bad Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openoffice-bin
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
PKG_JVMS_ACCEPTED=	jdk15 sun-jdk6
USE_JAVA=		run
.include "../../mk/java-vm.mk"
.endif
