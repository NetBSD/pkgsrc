# $NetBSD: hacks.mk,v 1.2 2005/01/24 20:48:35 tv Exp $

.ifndef DAR_HACKS_MK
DAR_HACKS_MK=		# defined

### [Mon Jan 24 16:39:35 UTC 2005 : tv]
### Interix has no <inttypes.h>/<stdint.h>
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		standard-headers
CONFIGURE_ARGS+=	--enable-os-bits=32
.endif

.endif
