# $NetBSD: buildlink3.mk,v 1.82 2024/10/20 14:03:26 wiz Exp $

BUILDLINK_TREE+=	streamtuner

.if !defined(STREAMTUNER_BUILDLINK3_MK)
STREAMTUNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.streamtuner+=	streamtuner>=0.99
BUILDLINK_ABI_DEPENDS.streamtuner+=	streamtuner>=0.99.99nb86
BUILDLINK_PKGSRCDIR.streamtuner?=	../../audio/streamtuner

.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # STREAMTUNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-streamtuner
