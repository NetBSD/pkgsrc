# $NetBSD: module.mk,v 1.8 2009/03/13 10:57:20 sborrill Exp $

# This file is now only needed to patch up PKGNAME until PHP 5.2.10 or later is
# released. 
.if "${PHP_BASE_VERS}" == "5.2.9"
PKGNAME=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.99
.endif
