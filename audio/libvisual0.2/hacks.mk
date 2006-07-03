# $NetBSD: hacks.mk,v 1.1.1.1 2006/07/03 23:29:50 wiz Exp $

.if !defined(LIBVISUAL_HACKS_MK)
LIBVISUAL_HACKS_MK=	# defined

# [ Mon Jan  2 13:49:14 CET 2006 : jmmv ]
# -funroll-loops breaks the inlined MMX code in libvisual/lv_video_mmx.c.
# It adds an immediate value to a movd instruction that does not let it
# compile.
BUILDLINK_TRANSFORM+=	rm:-funroll-loops

.endif
