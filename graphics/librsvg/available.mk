# $NetBSD: available.mk,v 1.7 2021/10/29 06:55:10 he Exp $
#
# This mk fragment defines the LIBRSVG_TYPE variable used in other librsvg mk
# fragments.
#
# User-settable variables:
#
# LIBRSVG_TYPE
#	Type of librsvg implementation used.
#
#	Possible values: c rust
#	Default: rust on platforms were Rust is supported
#

.if !defined(LIBRSVG_AVAILABLE_MK)
LIBRSVG_AVAILABLE_MK=	defined

.include "../../mk/bsd.prefs.mk"

.include "../../lang/rust/platform.mk"
.if !empty(PLATFORM_SUPPORTS_RUST:M[Yy][Ee][Ss])
LIBRSVG_TYPE?=	rust
.else
LIBRSVG_TYPE?=	c
.endif

.endif # LIBRSVG_AVAILABLE_MK
