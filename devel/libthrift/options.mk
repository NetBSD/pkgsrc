# $NetBSD: options.mk,v 1.2 2010/10/16 11:38:05 tonnerre Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libthrift
PKG_SUPPORTED_OPTIONS=	csharp java erlang python perl php ruby

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		perl erlang

.if !empty(PKG_OPTIONS:Mcsharp)
CONFIGURE_ARGS+=	--with-csharp
CONFIGURE_ARGS+=	--enable-gen-csharp

.include "../../lang/mono/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-csharp
CONFIGURE_ARGS+=	--disable-gen-csharp
.endif

.if !empty(PKG_OPTIONS:Mjava)
CONFIGURE_ARGS+=	--with-java
CONFIGURE_ARGS+=	--enable-gen-java

.include "../../lang/openjdk7/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--disable-gen-java
.endif

.if !empty(PKG_OPTIONS:Merlang)
CONFIGURE_ARGS+=	--with-erlang
CONFIGURE_ARGS+=	--enable-gen-erl
PLIST.erlang=		yes

.include "../../lang/erlang/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-erlang
CONFIGURE_ARGS+=	--disable-gen-erl
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-py
CONFIGURE_ARGS+=	--enable-gen-py

.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--without-py
CONFIGURE_ARGS+=	--disable-gen-py
.endif

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--enable-gen-perl
CONFIGURE_ENV+=		PERL_PREFIX=${PREFIX}
MAKE_ENV+=		INSTALLDIRS=vendor
PERL5_CONFIGURE=	NO
USE_TOOLS+=		perl
PLIST.perl=		yes

PERL5_PACKLIST=		auto/Thrift/.packlist

.include "../../lang/perl5/module.mk"
.else
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--disable-gen-perl
.endif

.if !empty(PKG_OPTIONS:Mphp)
CONFIGURE_ARGS+=	--with-php
CONFIGURE_ARGS+=	--enable-gen-php

.include "../../lang/php/ext.mk"
.else
CONFIGURE_ARGS+=	--without-php
CONFIGURE_ARGS+=	--disable-gen-php
.endif

.if !empty(PKG_OPTIONS:Mruby)
CONFIGURE_ARGS+=	--with-ruby
CONFIGURE_ARGS+=	--enable-gen-rb

.include "../../lang/ruby/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ruby
CONFIGURE_ARGS+=	--disable-gen-rb
.endif
