# $NetBSD: rust.mk,v 1.20 2026/04/04 18:48:49 tnn Exp $
#
# This file determines the type of rust package to use.
#
# It should be included by rust-dependent packages that don't use
# cargo.mk.
#
# === User-settable variables ===
#
# RUST_TYPE
#	The preferred type of Rust release to use - either build from source,
#	or use a binary installation.
#
#	Official Rust binaries are only published for certain platforms.  The
#	"bin" option uses the lang/rust-bin package, whereas "native" uses
#	binaries installed on the host system.  If using "native" with a rustup
#	installation, you will probably also need to set RUSTUP_HOME in your
#	MAKE_ENV pointing to the 'rustup show home' directory.  This is due to
#	pkgsrc overwriting the HOME environment variable during build.
#
#	Possible values: src bin native
#	Default: "src", except on 32-bit arm where it's "bin"
#
# === Package-settable variables ===
#
# RUST_REQ
#	The minimum version of Rust required by the package.
#
#	Default: 1.85.0
#
# RUST_RUNTIME
#	Whether rust is a runtime dependency.
#	Usually it is only needed to build.
#
#	Possible values: yes no
#	Default: no

.include "../../mk/bsd.fast.prefs.mk"
.include "platform.mk"

RUST_REQ?=	1.85.0
RUST_RUNTIME?=	no

.if ${MACHINE_PLATFORM:M*-*-earm*}
RUST_TYPE?=	bin
.else
RUST_TYPE?=	src
.endif

.if ${RUST_TYPE} == "bin"
.  if ${RUST_RUNTIME} == "no"
BUILDLINK_DEPMETHOD.rust-bin?=		build
.  endif
BUILDLINK_API_DEPENDS.rust-bin+=	rust-bin>=${RUST_REQ}
.  include "${RUST_DIR}-bin/buildlink3.mk"
.endif

.if ${RUST_TYPE} == "src"
.  if ${RUST_RUNTIME} == "no"
BUILDLINK_DEPMETHOD.rust?=		build
.  endif
BUILDLINK_API_DEPENDS.rust+=		rust>=${RUST_REQ}
.  include "${RUST_DIR}/buildlink3.mk"
.endif

.if ${OPSYS} == "NetBSD"
ALL_ENV+=	PTHREAD_KEYS_MAX=512
.endif
