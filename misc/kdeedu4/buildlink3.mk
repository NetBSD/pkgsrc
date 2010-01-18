# $NetBSD: buildlink3.mk,v 1.3 2010/01/18 09:59:14 wiz Exp $

BUILDLINK_TREE+=	kdeedu4

.if !defined(KDEEDU4_BUILDLINK3_MK)
KDEEDU4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdeedu4+=	kdeedu4>=4.1.1
BUILDLINK_ABI_DEPENDS.kdeedu4?=	kdeedu4>=4.3.4nb2
BUILDLINK_PKGSRCDIR.kdeedu4?=	../../misc/kdeedu4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDEEDU4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdeedu4
