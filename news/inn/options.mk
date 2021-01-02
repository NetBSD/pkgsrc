# $NetBSD: options.mk,v 1.9 2021/01/02 14:18:22 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.inn
PKG_SUPPORTED_OPTIONS=	perl python uucp kerberos gnupg2
PKG_SUGGESTED_OPTIONS=	perl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		kerberos

###
### uucp support (requires a group uucp to exist)
###
.if !empty(PKG_OPTIONS:Muucp)
PKG_GROUPS_VARS+=       UUCP_GROUP
PKG_GROUPS+=		${UUCP_GROUP}

CONFIGURE_ARGS+=	--enable-uucp-rnews
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

###
### kerberos support for INN
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"

CONFIGURE_ARGS+=	--with-krb5
.else
CONFIGURE_ARGS+=	--without-krb5
.endif

###
### pick either gnupg2 or gnupg
###
.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=               gnupg2-[0-9]*:../../security/gnupg2
.else
DEPENDS+=               gnupg-[0-9]*:../../security/gnupg
.endif

