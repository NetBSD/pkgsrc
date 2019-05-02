# $NetBSD: options.mk,v 1.2 2019/05/02 08:36:10 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libreoffice-bin
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
PKG_JVMS_ACCEPTED=	jdk15
USE_JAVA=		run
.include "../../mk/java-vm.mk"
.endif
