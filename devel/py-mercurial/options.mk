# $NetBSD: options.mk,v 1.4 2020/11/09 14:59:10 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mercurial
# 5.6 needs some "*-pre" crates that are not available
# then it fails with a missing Cargo.toml file error
PKG_SUPPORTED_OPTIONS=		# rust
PKG_SUGGESTED_OPTIONS=		# rust

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	rust

.if !empty(PKG_OPTIONS:Mrust)
PLIST.rust=	yes
PYSETUPARGS+=	--rust
# for python3-sys
MAKE_ENV+=	PYTHON_SYS_EXECUTABLE=${PYTHONBIN}

# When updating:
#	  cd ${WRKSRC}
#	  cat $(find .. -name Cargo.lock) > Cargo.lock
#	  cd -
#	  make show-cargo-depends | sort -u
#
# After updating, check:
#         hg debuginstall | grep -i rust
# to validate rust is in use
#
# Two steps of tests work, but then fail with
# mercurial-5.5/rust/target/debug/deps/rusthg-a55fe645bc4ab58d: Shared object "libpython3.7.so.1.0" not found

.include "cargo-depends.mk"

RUST_REQ+=	1.34.2
.include "../../lang/rust/cargo.mk"
.else
TEST_MAKE_FLAGS+=       CARGO=/dev/null
.endif
