# $NetBSD: buildlink3.mk,v 1.12 2012/03/03 00:12:04 wiz Exp $

BUILDLINK_TREE+=	fluidsynth

.if !defined(FLUIDSYNTH_BUILDLINK3_MK)
FLUIDSYNTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fluidsynth+=	fluidsynth>=1.0.5
BUILDLINK_ABI_DEPENDS.fluidsynth+=	fluidsynth>=1.1.5nb2
BUILDLINK_PKGSRCDIR.fluidsynth?=	../../audio/fluidsynth

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # FLUIDSYNTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fluidsynth
