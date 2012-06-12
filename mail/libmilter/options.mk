# $NetBSD: options.mk,v 1.2 2012/06/12 15:45:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmilter
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

# IPv6 support is handled directly in ../sendmail/Makefile.common
