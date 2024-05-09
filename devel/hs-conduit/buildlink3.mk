# $NetBSD: buildlink3.mk,v 1.17 2024/05/09 01:31:50 pho Exp $

BUILDLINK_TREE+=	hs-conduit

.if !defined(HS_CONDUIT_BUILDLINK3_MK)
HS_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-conduit+=	hs-conduit>=1.3.5
BUILDLINK_ABI_DEPENDS.hs-conduit+=	hs-conduit>=1.3.5nb2
BUILDLINK_PKGSRCDIR.hs-conduit?=	../../devel/hs-conduit

.include "../../devel/hs-mono-traversable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-conduit
