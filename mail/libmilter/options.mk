# $NetBSD: options.mk,v 1.1 2007/09/25 20:05:24 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmilter
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

# IPv6 support is handled directly in ../sendmail/Makefile.common
