# $NetBSD: hacks.mk,v 1.1 2011/03/02 04:33:23 minskim Exp $

.if !defined(PDVIPSK_HACKS_MK)
PDVIPSK_HACKS_MK=	# defined

### NetBSD's patch(1) fails in patching dvips.info.
###
.if ${OPSYS} == "NetBSD"
BUILD_DEPENDS+=	patch-[0-9]*:../../devel/patch

PATCH=		${LOCALBASE}/bin/gpatch
PKG_HACKS+=	patch-dvips_info
.endif

.endif
