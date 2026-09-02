# $NetBSD: buildlink3.mk,v 1.98 2026/09/02 19:01:01 wiz Exp $

BUILDLINK_TREE+=	streamtuner

.if !defined(STREAMTUNER_BUILDLINK3_MK)
STREAMTUNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.streamtuner+=	streamtuner>=0.99
BUILDLINK_ABI_DEPENDS.streamtuner+=	streamtuner>=0.99.99nb102
BUILDLINK_PKGSRCDIR.streamtuner?=	../../audio/streamtuner

.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # STREAMTUNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-streamtuner
