# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	fluidsynth

.if !defined(FLUIDSYNTH_BUILDLINK3_MK)
FLUIDSYNTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fluidsynth+=		fluidsynth>=1.0.5
BUILDLINK_PKGSRCDIR.fluidsynth?=	../../audio/fluidsynth

.include "../../devel/readline/buildlink3.mk"
.endif # FLUIDSYNTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fluidsynth
