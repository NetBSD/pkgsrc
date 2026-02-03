# $NetBSD: options.mk,v 1.1 2026/02/03 16:00:33 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	ruby-build-ri-db
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db

.for a in x86_64 aarch64 aarch64eb arm64
.  if ${a} == ${MACHINE_ARCH}
PKG_OPTIONS_REQUIRED_GROUPS=	jit
PKG_OPTIONS_GROUP.jit=		ruby-yjit # ruby-zjit
PKG_SUGGESTED_OPTIONS+=		ruby-yjit
.  endif
.endfor

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mruby-yjit}
CONFIGURE_ARGS+=	--enable-yjit --disable-zjit
RUST_REQ=		1.58.0
.include "../../lang/rust/rust.mk"
.endif

#.if ${PKG_OPTIONS:Mruby-zjit}
#CONFIGURE_ARGS+=	--disable-yjit --enable-zjit
#RUST_REQ=		1.85.0
#.include "../../lang/rust/rust.mk"
#.endif

.if !defined(RUST_REQ)
CONFIGURE_ARGS+=	--disable-yjit --disable-zjit
.endif

.if ${PKG_OPTIONS:Mruby-build-ri-db}
RUBY_DYNAMIC_DIRS+=	${RUBY_SYSRIDIR}
# Use huge memory.
UNLIMIT_RESOURCES+=	datasize
.else
CONFIGURE_ARGS+=	--enable-install-doc=no
.endif
