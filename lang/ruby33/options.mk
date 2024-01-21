# $NetBSD: options.mk,v 1.1 2024/01/21 08:22:02 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	ruby-build-ri-db
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db

.for a in x86_64 aarch64 aarch64eb arm64
.  if ${a} == ${MACHINE_ARCH}
PKG_OPTIONS_REQUIRED_GROUPS=	jit
PKG_OPTIONS_GROUP.jit=		ruby-rjit ruby-yjit
PKG_SUGGESTED_OPTIONS+=		ruby-yjit
.  endif
.endfor

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mruby-yjit}
CONFIGURE_ARGS+=	--disable-rjit --enable-yjit
RUST_REQ=		1.58.0
.include "../../lang/rust/rust.mk"
.else
CONFIGURE_ENV+=		RUSTC=no
.endif

.if ${PKG_OPTIONS:Mruby-rjit}
CONFIGURE_ARGS+=	--enable-rjit --disable-yjit
.endif

.if ${PKG_OPTIONS:Mruby-build-ri-db}
RUBY_DYNAMIC_DIRS+=	${RUBY_SYSRIDIR}
# Use huge memory.
UNLIMIT_RESOURCES+=	datasize
.else
CONFIGURE_ARGS+=	--enable-install-doc=no
.endif
