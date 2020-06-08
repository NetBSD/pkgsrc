# $NetBSD: buildlink3.mk,v 1.10 2020/06/08 13:42:38 wiz Exp $

BUILDLINK_TREE+=	ntl

.if !defined(NTL_BUILDLINK3_MK)
NTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ntl+=	ntl>=11.4.3
BUILDLINK_PKGSRCDIR.ntl?=	../../math/ntl

BUILDLINK_DEPMETHOD.ntl?=	build

.include "../../devel/gmp/buildlink3.mk"
.endif # NTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ntl
