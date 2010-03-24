# $NetBSD: buildlink3.mk,v 1.8 2010/03/24 21:54:16 asau Exp $

BUILDLINK_TREE+=	ntl

.if !defined(NTL_BUILDLINK3_MK)
NTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ntl+=	ntl>=5.3.1
BUILDLINK_ABI_DEPENDS.ntl+=	ntl>=5.3.1nb2
BUILDLINK_PKGSRCDIR.ntl?=	../../math/ntl

.include "../../devel/gmp/buildlink3.mk"
.endif # NTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ntl
