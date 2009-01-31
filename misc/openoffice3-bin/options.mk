# $NetBSD: options.mk,v 1.1.1.1 2009/01/31 22:05:53 bad Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openoffice-bin
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
PKG_JVMS_ACCEPTED=	blackdown-jdk13 sun-jdk13 sun-jdk14 sun-jdk15
USE_JAVA=		run
.include "../../mk/java-vm.mk"
.endif
