# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:39 wiz Exp $

BUILDLINK_TREE+=	atkmm2.36

.if !defined(ATKMM2.36_BUILDLINK3_MK)
ATKMM2.36_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atkmm2.36+=	atkmm2.36>=2.36.1
BUILDLINK_ABI_DEPENDS.atkmm2.36?=	atkmm2.36>=2.36.1nb2
BUILDLINK_PKGSRCDIR.atkmm2.36?=	../../devel/atkmm2.36

GCC_REQD+=	4.9

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glibmm2.68/buildlink3.mk"
.endif	# ATKMM2.36_BUILDLINK3_MK

BUILDLINK_TREE+=	-atkmm2.36
