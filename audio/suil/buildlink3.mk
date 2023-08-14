# $NetBSD: buildlink3.mk,v 1.21 2023/08/14 05:23:50 wiz Exp $

BUILDLINK_TREE+=	suil

.if !defined(SUIL_BUILDLINK3_MK)
SUIL_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.suil+=	suil>=0.10.12nb6
BUILDLINK_API_DEPENDS.suil+=	suil>=0.8.2
BUILDLINK_PKGSRCDIR.suil?=	../../audio/suil

.include "../../audio/lv2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# SUIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-suil
