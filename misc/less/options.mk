# $NetBSD: options.mk,v 1.2 2019/06/15 10:03:38 leot Exp $

PKG_OPTIONS_VAR=	 	PKG_OPTIONS.less
PKG_OPTIONS_REQUIRED_GROUPS=	regex
PKG_OPTIONS_GROUP.regex=	pcre regexp
PKG_SUGGESTED_OPTIONS=	 	regexp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+= 	--with-regex=pcre
.  include "../../devel/pcre/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mregexp)
CONFIGURE_ARGS+= 	--with-regex=posix
.endif
