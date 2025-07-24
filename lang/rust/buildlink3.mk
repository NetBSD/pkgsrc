# $NetBSD: buildlink3.mk,v 1.18 2025/07/24 10:33:38 jperkin Exp $

BUILDLINK_TREE+=	rust

#
# DO NOT include this directly! Use rust.mk instead.
#

.if !defined(RUST_BUILDLINK3_MK)
RUST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rust+=	rust>=1.56.1
BUILDLINK_PKGSRCDIR.rust?=	../../lang/rust
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/lib/rustlib

.include "../../mk/bsd.fast.prefs.mk"

pkgbase:= rust
.include "../../mk/pkg-build-options.mk"
# XXX: unclear why this is necessary, but is actively harmful on Darwin, and
# likely broken for most uses anyway as rust defaults to DEPMETHOD=build.
.if empty(PKG_BUILD_OPTIONS.rust:Mrust-internal-llvm) && ${OPSYS} != "Darwin"
.  include "../../lang/libunwind/buildlink3.mk"
.endif

.endif

BUILDLINK_TREE+=	-rust
