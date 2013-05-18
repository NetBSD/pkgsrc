# $NetBSD: buildlink3.mk,v 1.9 2013/05/18 18:32:19 agc Exp $

BUILDLINK_TREE+=	ntl

.if !defined(NTL_BUILDLINK3_MK)
NTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ntl+=	ntl>=6.0.0
BUILDLINK_ABI_DEPENDS.ntl+=	ntl>=6.0.0
BUILDLINK_PKGSRCDIR.ntl?=	../../math/ntl

.include "../../devel/gmp/buildlink3.mk"
.endif # NTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ntl
