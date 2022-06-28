# $NetBSD: buildlink3.mk,v 1.11 2022/06/28 11:34:37 wiz Exp $

BUILDLINK_TREE+=	ntl

.if !defined(NTL_BUILDLINK3_MK)
NTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ntl+=	ntl>=11.4.3
BUILDLINK_ABI_DEPENDS.ntl?=	ntl>=11.5.1nb1
BUILDLINK_PKGSRCDIR.ntl?=	../../math/ntl

BUILDLINK_DEPMETHOD.ntl?=	build

.include "../../devel/gmp/buildlink3.mk"
.endif # NTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ntl
