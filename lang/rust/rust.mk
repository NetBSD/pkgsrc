# $NetBSD: rust.mk,v 1.8 2022/07/01 06:58:18 pin Exp $
#
# This file determines the type of rust package to use.
#
# It should be included by rust-dependent packages that don't use
# cargo.mk.
#
# === User-settable variables ===
#
# RUST_TYPE
#	The preferred type of Rust release to use -
#	either bootstrap-from-source or an official binary.
#
#	Official Rust binaries are only published for certain platforms,
#	including Darwin, FreeBSD, Linux, and NetBSD x86_64.
#
#	Possible values: src bin
#	Default: src
#
# === Package-settable variables ===
#
# RUST_REQ
#	The minimum version of Rust required by the package.
#
#	Default: 1.56.1
#
# RUST_RUNTIME
#	Whether rust is a runtime dependency.
#	Usually it is only needed to build.
#
#	Possible values: yes no
#	Default: no

.include "../../mk/bsd.fast.prefs.mk"

RUST_REQ?=	1.56.1
RUST_RUNTIME?=	no

RUST_TYPE?=	src

.if ${RUST_TYPE} == "bin"
.  if ${RUST_RUNTIME} == "no"
BUILDLINK_DEPMETHOD.rust-bin?=		build
.  endif
BUILDLINK_API_DEPENDS.rust-bin+=	rust-bin>=${RUST_REQ}
.  include "../../lang/rust-bin/buildlink3.mk"
.endif

.if ${RUST_TYPE} == "src"
.  if ${RUST_RUNTIME} == "no"
BUILDLINK_DEPMETHOD.rust?=		build
.  endif
BUILDLINK_API_DEPENDS.rust+=		rust>=${RUST_REQ}
.  include "../../lang/rust/buildlink3.mk"
.endif
