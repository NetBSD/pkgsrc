# $NetBSD: options.mk,v 1.4 2007/09/24 21:58:28 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	ruby-build-ri-db
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mruby-build-ri-db)
CONFIGURE_ARGS+=	--enable-install-doc
PRIVILEGED_STAGES+=    clean
RUBY_DYNAMIC_DIRS+=	${RUBY_SYSRIDIR}
.endif
