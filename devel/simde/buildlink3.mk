# $NetBSD: buildlink3.mk,v 1.2 2023/07/09 08:28:37 nia Exp $

BUILDLINK_TREE+=	simde

.if !defined(SIMDE_BUILDLINK3_MK)
SIMDE_BUILDLINK3_MK:=

# .buildlink/include/simde/x86/sse2.h:5293:3:
# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES+=	c99

BUILDLINK_API_DEPENDS.simde+=	simde>=0.7.2
BUILDLINK_PKGSRCDIR.simde?=	../../devel/simde
BUILDLINK_DEPMETHOD.simde?=	build
.endif	# SIMDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-simde
