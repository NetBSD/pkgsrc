# $NetBSD: available.mk,v 1.2 2020/06/17 10:13:25 nia Exp $
#
# This mk fragment define LIBRSVG_TYPE variable used in other librsvg mk
# fragments.
#
# User-settable variables:
#
# LIBRSVG_TYPE
#	Type of used librsvg implementation.
#
#	Possible values: c rust
#	Default: rust on platforms were Rust is supported
#

.if !defined(LIBRSVG_AVAILABLE_MK)
LIBRSVG_AVAILABLE_MK=	defined

.include "../../mk/bsd.prefs.mk"

.include "../../lang/rust/platform.mk"
# https://mail-index.netbsd.org/tech-pkg/2020/06/16/msg023380.html
.if !empty(PLATFORM_SUPPORTS_RUST:M[Yy][Ee][Ss]) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-earm*)
LIBRSVG_TYPE?=	rust
.else
LIBRSVG_TYPE?=	c
.endif

.endif # LIBRSVG_AVAILABLE_MK
