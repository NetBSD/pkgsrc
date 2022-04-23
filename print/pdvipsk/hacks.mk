# $NetBSD: hacks.mk,v 1.4 2022/04/23 23:56:23 tnn Exp $

.if !defined(PDVIPSK_HACKS_MK)
PDVIPSK_HACKS_MK=	# defined

### NetBSD's patch(1) fails in patching dvips.info.
###
BUILD_DEPENDS+=	patch-[0-9]*:../../devel/patch

PATCH=			${LOCALBASE}/bin/gpatch
PKG_HACKS+=		patch-dvips_info
.endif
