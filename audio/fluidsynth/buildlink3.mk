# $NetBSD: buildlink3.mk,v 1.15 2020/03/08 16:47:24 wiz Exp $

BUILDLINK_TREE+=	fluidsynth

.if !defined(FLUIDSYNTH_BUILDLINK3_MK)
FLUIDSYNTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fluidsynth+=	fluidsynth>=1.0.5
BUILDLINK_ABI_DEPENDS.fluidsynth+=	fluidsynth>=2.1.1nb1
BUILDLINK_PKGSRCDIR.fluidsynth?=	../../audio/fluidsynth

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.endif # FLUIDSYNTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fluidsynth
