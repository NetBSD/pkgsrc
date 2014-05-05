# $NetBSD: buildlink3.mk,v 1.38 2014/05/05 00:47:38 ryoon Exp $

BUILDLINK_TREE+=	streamtuner

.if !defined(STREAMTUNER_BUILDLINK3_MK)
STREAMTUNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.streamtuner+=		streamtuner>=0.99
BUILDLINK_ABI_DEPENDS.streamtuner+=	streamtuner>=0.99.99nb35
BUILDLINK_PKGSRCDIR.streamtuner?=	../../audio/streamtuner

.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # STREAMTUNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-streamtuner
