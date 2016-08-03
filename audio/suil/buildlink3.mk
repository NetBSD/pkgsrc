# $NetBSD: buildlink3.mk,v 1.2 2016/08/03 10:22:08 adam Exp $

BUILDLINK_TREE+=	suil

.if !defined(SUIL_BUILDLINK3_MK)
SUIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.suil+=	suil>=0.8.2
BUILDLINK_ABI_DEPENDS.suil?=	suil>=0.8.2nb1
BUILDLINK_PKGSRCDIR.suil?=	../../audio/suil

.include "../../audio/lv2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# SUIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-suil
