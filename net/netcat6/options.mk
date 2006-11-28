# $NetBSD: options.mk,v 1.2 2006/11/28 16:28:55 tv Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.netcat6
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
