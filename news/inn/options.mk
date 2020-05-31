# $NetBSD: options.mk,v 1.8 2020/05/31 15:08:27 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.inn
PKG_SUPPORTED_OPTIONS=	perl python uucp
PKG_SUGGESTED_OPTIONS=	perl

.include "../../mk/bsd.options.mk"

###
### uucp support (requires a group uucp to exist)
###
.if !empty(PKG_OPTIONS:Muucp)
CONFIGURE_ARGS+=	--enable-uucp-rnews
PKG_GROUPS+=		uucp
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
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		_PATH_PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.endif
