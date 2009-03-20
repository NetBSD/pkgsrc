# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	ntl

.if !defined(NTL_BUILDLINK3_MK)
NTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ntl+=	ntl>=5.3.1
BUILDLINK_ABI_DEPENDS.ntl+=	ntl>=5.3.1nb1
BUILDLINK_PKGSRCDIR.ntl?=	../../math/ntl

.include "../../devel/gmp/buildlink3.mk"
.endif # NTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ntl
