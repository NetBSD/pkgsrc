# $NetBSD: hacks.mk,v 1.1 2005/01/24 16:58:06 tv Exp $

.ifndef DAR_HACKS_MK
DAR_HACKS_MK=		# defined

### [Mon Jan 24 16:39:35 UTC 2005 : tv]
### Interix has no <inttypes.h>/<stdint.h>
###
.if ${OPSYS} == "Interix"
CONFIGURE_ARGS+=	--enable-os-bits=32
.endif

.endif
