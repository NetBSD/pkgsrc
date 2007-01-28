# $NetBSD: options.mk,v 1.2 2007/01/28 15:15:58 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=		ruby-build-ri-db

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mruby-build-ri-db)
CONFIGURE_ARGS+=	--enable-install-doc
RUBY_DYNAMIC_DIRS+=	${RUBY_SYSRIDIR}
.endif
