# $NetBSD: options.mk,v 1.2 2010/03/03 21:39:49 bad Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openoffice-bin
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
PKG_JVMS_ACCEPTED=	sun-jdk15 sun-jdk6 openjdk7 openjdk7-bin
USE_JAVA=		run
.include "../../mk/java-vm.mk"
.endif
