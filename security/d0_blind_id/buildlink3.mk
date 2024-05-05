# $NetBSD: buildlink3.mk,v 1.1 2024/05/05 08:53:22 nia Exp $

BUILDLINK_TREE+=	d0_blind_id

.if !defined(D0_BLIND_ID_BUILDLINK3_MK)
D0_BLIND_ID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.d0_blind_id+=	d0_blind_id>=1.0
BUILDLINK_PKGSRCDIR.d0_blind_id?=	../../security/d0_blind_id

.include "../../devel/gmp/buildlink3.mk"
.endif	# D0_BLIND_ID_BUILDLINK3_MK

BUILDLINK_TREE+=	-d0_blind_id
