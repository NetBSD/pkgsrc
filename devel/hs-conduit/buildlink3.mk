# $NetBSD: buildlink3.mk,v 1.16 2023/11/02 06:36:23 pho Exp $

BUILDLINK_TREE+=	hs-conduit

.if !defined(HS_CONDUIT_BUILDLINK3_MK)
HS_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-conduit+=	hs-conduit>=1.3.5
BUILDLINK_ABI_DEPENDS.hs-conduit+=	hs-conduit>=1.3.5nb1
BUILDLINK_PKGSRCDIR.hs-conduit?=	../../devel/hs-conduit

.include "../../devel/hs-mono-traversable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-conduit
