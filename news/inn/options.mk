# $NetBSD: options.mk,v 1.3 2007/09/07 22:12:20 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.inn
PKG_SUPPORTED_OPTIONS=	inet6 python
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

###
### Python support for INN
###
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=       --with-python
CONFIGURE_ENV+=		_PATH_PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.endif
