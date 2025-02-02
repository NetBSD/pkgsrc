# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:01 pho Exp $

BUILDLINK_TREE+=	hs-conduit-parse

.if !defined(HS_CONDUIT_PARSE_BUILDLINK3_MK)
HS_CONDUIT_PARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-conduit-parse+=	hs-conduit-parse>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-conduit-parse+=	hs-conduit-parse>=0.2.1.1nb1
BUILDLINK_PKGSRCDIR.hs-conduit-parse?=		../../devel/hs-conduit-parse

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../textproc/hs-parsers/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.endif	# HS_CONDUIT_PARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-conduit-parse
