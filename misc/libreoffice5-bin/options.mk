# $NetBSD: options.mk,v 1.1 2016/01/08 23:53:13 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libreoffice-bin
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
PKG_JVMS_ACCEPTED=	jdk15 sun-jdk6
USE_JAVA=		run
.include "../../mk/java-vm.mk"
.endif
