# $NetBSD: available.mk,v 1.1 2023/07/21 16:03:38 hauke Exp $
#
# This mk fragment defines the LIBIMAGEQUANT_TYPE variable used in
# other libimagequant mk fragments.
#
# User-settable variables:
#
# LIBIMAGEQUANT_TYPE
#	Type of libimagequant implementation used.
#
#	Possible values: c rust
#	Default: rust on platforms were Rust is supported
#

.if !defined(LIBIMAGEQUANT_AVAILABLE_MK)
LIBIMAGEQUANT_AVAILABLE_MK=	defined

.include "../../mk/bsd.prefs.mk"

.include "../../lang/rust/platform.mk"
.if ${PLATFORM_SUPPORTS_RUST:tl} == "yes"
LIBIMAGEQUANT_TYPE?=	rust
.else
LIBIMAGEQUANT_TYPE?=	c
.endif

.endif # LIBIMAGEQUANT_AVAILABLE_MK
