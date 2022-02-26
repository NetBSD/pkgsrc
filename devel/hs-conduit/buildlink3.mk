# $NetBSD: buildlink3.mk,v 1.9 2022/02/26 03:57:51 pho Exp $

BUILDLINK_TREE+=	hs-conduit

.if !defined(HS_CONDUIT_BUILDLINK3_MK)
HS_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-conduit+=	hs-conduit>=1.3.4
BUILDLINK_ABI_DEPENDS.hs-conduit+=	hs-conduit>=1.3.4.2nb2
BUILDLINK_PKGSRCDIR.hs-conduit?=	../../devel/hs-conduit

.include "../../devel/hs-mono-traversable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-conduit
