# $NetBSD: buildlink3.mk,v 1.6 2012/05/07 01:53:35 dholland Exp $

BUILDLINK_TREE+=	lensfun

.if !defined(LENSFUN_BUILDLINK3_MK)
LENSFUN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lensfun+=	lensfun>=0.2.2b
BUILDLINK_ABI_DEPENDS.lensfun+=	lensfun>=0.2.5nb8
BUILDLINK_PKGSRCDIR.lensfun?=	../../graphics/lensfun

.include "../../devel/glib2/buildlink3.mk"
.endif # LENSFUN_BUILDLINK3_MK

BUILDLINK_TREE+=	-lensfun
