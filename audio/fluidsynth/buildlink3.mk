# $NetBSD: buildlink3.mk,v 1.14 2013/07/17 12:24:41 obache Exp $

BUILDLINK_TREE+=	fluidsynth

.if !defined(FLUIDSYNTH_BUILDLINK3_MK)
FLUIDSYNTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fluidsynth+=	fluidsynth>=1.0.5
BUILDLINK_ABI_DEPENDS.fluidsynth+=	fluidsynth>=1.1.6nb1
BUILDLINK_PKGSRCDIR.fluidsynth?=	../../audio/fluidsynth

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.endif # FLUIDSYNTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-fluidsynth
