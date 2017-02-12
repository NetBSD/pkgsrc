# $NetBSD: buildlink3.mk,v 1.4 2017/02/12 06:24:37 ryoon Exp $

BUILDLINK_TREE+=	suil

.if !defined(SUIL_BUILDLINK3_MK)
SUIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.suil+=	suil>=0.8.2
BUILDLINK_ABI_DEPENDS.suil?=	suil>=0.8.2nb3
BUILDLINK_PKGSRCDIR.suil?=	../../audio/suil

.include "../../audio/lv2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# SUIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-suil
