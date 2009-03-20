# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	goom

.if !defined(GOOM_BUILDLINK3_MK)
GOOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goom+=	goom>=2004.0
BUILDLINK_PKGSRCDIR.goom?=	../../audio/goom
.endif # GOOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-goom
