# $NetBSD: options.mk,v 1.5 2009/12/16 22:10:25 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.inn
PKG_SUPPORTED_OPTIONS=	inet6 perl python uucp
PKG_SUGGESTED_OPTIONS=	inet6 perl

.include "../../mk/bsd.options.mk"

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

###
### uucp support (requires a group uucp to exist)
###
.if !empty(PKG_OPTIONS:Muucp)
CONFIGURE_ARGS+=	--enable-uucp-rnews
PKG_GROUPS+= uucp
.else
CONFIGURE_ARGS+=	--disable-uucp-rnews
.endif

###
### perl support for INN
###
.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		_PATH_PERL=${PERL5:Q}

.include "../../lang/perl5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-perl
.endif
###
### Python support for INN
###
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=       --with-python
CONFIGURE_ENV+=		_PATH_PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.endif
