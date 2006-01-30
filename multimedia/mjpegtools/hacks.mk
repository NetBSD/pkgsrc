#	$NetBSD: hacks.mk,v 1.3 2006/01/30 08:44:25 xtraeme Exp $

.if !defined(MJPEGTOOLS_HACKS_MK)
MJPEGTOOLS_HACKS_MK= defined

### Hack to work around MacOS X 4.x (and probably other)'s gcc 4.x
### which does not understand -fmove-all-movables. Remove that option
### if gcc-4 is used.
###
.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.*)
BUILDLINK_TRANSFORM+=   rm:-fmove-all-movables
.endif

.endif	# MJPEGTOOLS_HACKS_MK
