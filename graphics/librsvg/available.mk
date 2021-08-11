# $NetBSD: available.mk,v 1.6 2021/08/11 00:25:35 gutteridge Exp $
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
# https://mail-index.netbsd.org/tech-pkg/2020/06/16/msg023380.html
.if !empty(PLATFORM_SUPPORTS_RUST:M[Yy][Ee][Ss]) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-earm*) && \
    empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
LIBRSVG_TYPE?=	rust
.else
LIBRSVG_TYPE?=	c
.endif

.endif # LIBRSVG_AVAILABLE_MK
