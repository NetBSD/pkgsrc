# $NetBSD: hacks.mk,v 1.3 2005/12/05 20:49:47 rillig Exp $

.if !defined(DAR_HACKS_MK)
DAR_HACKS_MK=		# defined

### [Mon Jan 24 16:39:35 UTC 2005 : tv]
### Interix has no <inttypes.h>/<stdint.h>
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		standard-headers
CONFIGURE_ARGS+=	--enable-os-bits=32
.endif

.endif
