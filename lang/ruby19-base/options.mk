# $NetBSD: options.mk,v 1.1.1.1 2010/09/12 03:50:06 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	ruby-build-ri-db
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mruby-build-ri-db)
BUILD_TARGET=		all rdoc
CONFIGURE_ARGS+=	--enable-install-doc
#PRIVILEGED_STAGES+=    clean
RUBY_DYNAMIC_DIRS+=	${RUBY_SYSRIDIR}
# Use huge memory.
UNLIMIT_RESOURCES+=	datasize
.endif
