# $NetBSD: Makefile,v 1.27 2006/04/18 22:39:32 adrianp Exp $
#

.include "Makefile.common"

COMMENT=	The Open Source Network Intrusion Detection System

PKG_OPTIONS_VAR=        PKG_OPTIONS.snort
PKG_SUPPORTED_OPTIONS=  debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.endif

.include "../../mk/bsd.pkg.mk"
