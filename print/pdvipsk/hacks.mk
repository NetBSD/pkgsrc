# $NetBSD: hacks.mk,v 1.3 2019/11/04 19:58:00 rillig Exp $

.if !defined(PDVIPSK_HACKS_MK)
PDVIPSK_HACKS_MK=	# defined

### NetBSD's patch(1) fails in patching dvips.info.
###
.if ${OPSYS} == "NetBSD"
BUILD_DEPENDS+=	patch-[0-9]*:../../devel/patch

PATCH=			${LOCALBASE}/bin/gpatch
PKG_HACKS+=		patch-dvips_info
.elif ${OPSYS} == "Darwin"
TOOLS_PLATFORM.patch=	/usr/bin/patch
PKG_HACKS+=		patch-dvips_info
.endif

.endif
