# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:20 pho Exp $

BUILDLINK_TREE+=	hs-crypton-conduit

.if !defined(HS_CRYPTON_CONDUIT_BUILDLINK3_MK)
HS_CRYPTON_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypton-conduit+=	hs-crypton-conduit>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-crypton-conduit+=	hs-crypton-conduit>=0.2.3nb1
BUILDLINK_PKGSRCDIR.hs-crypton-conduit?=	../../security/hs-crypton-conduit

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.endif	# HS_CRYPTON_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypton-conduit
