# $NetBSD: options.mk,v 1.3 2024/01/16 15:17:41 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	ruby-build-ri-db ruby-yjit
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db

.for a in x86_64 aarch64 aarch64eb
.  if ${a} == ${MACHINE_ARCH}
PKG_SUGGESTED_OPTIONS+=	ruby-yjit
.  endif
.endfor

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
