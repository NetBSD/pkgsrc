# $NetBSD: buildlink3.mk,v 1.13 2026/09/27 11:36:51 tnn Exp $

BUILDLINK_TREE+=	lensfun

.if !defined(LENSFUN_BUILDLINK3_MK)
LENSFUN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lensfun+=	lensfun>=0.2.2b
BUILDLINK_ABI_DEPENDS.lensfun+=	lensfun>=0.3.4nb4
BUILDLINK_PKGSRCDIR.lensfun?=	../../graphics/lensfun

.include "../../devel/glib2/buildlink3.mk"
.endif # LENSFUN_BUILDLINK3_MK

BUILDLINK_TREE+=	-lensfun
