# $NetBSD: buildlink3.mk,v 1.1 2021/05/31 22:28:38 wiz Exp $

BUILDLINK_TREE+=	atkmm2.36

.if !defined(ATKMM2.36_BUILDLINK3_MK)
ATKMM2.36_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atkmm2.36+=	atkmm2.36>=2.36.1
BUILDLINK_PKGSRCDIR.atkmm2.36?=	../../devel/atkmm2.36

GCC_REQD+=	4.9

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glibmm2.68/buildlink3.mk"
.endif	# ATKMM2.36_BUILDLINK3_MK

BUILDLINK_TREE+=	-atkmm2.36
