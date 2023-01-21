# $NetBSD: options.mk,v 1.1 2023/01/21 13:51:23 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	ruby-build-ri-db ruby-yjit
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db ruby-yjit

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mruby-yjit}
CONFIGURE_ARGS+=	--enable-yjit
RUST_REQ=		1.58.0
.include "../../lang/rust/rust.mk"
.else
CONFIGURE_ENV+=		RUSTC=no
.endif

.if ${PKG_OPTIONS:Mruby-build-ri-db}
RUBY_DYNAMIC_DIRS+=	${RUBY_SYSRIDIR}
# Use huge memory.
UNLIMIT_RESOURCES+=	datasize
.else
CONFIGURE_ARGS+=	--enable-install-doc=no
.endif
