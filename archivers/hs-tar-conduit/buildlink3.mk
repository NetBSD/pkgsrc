# $NetBSD: buildlink3.mk,v 1.1 2025/01/05 11:46:47 pho Exp $

BUILDLINK_TREE+=	hs-tar-conduit

.if !defined(HS_TAR_CONDUIT_BUILDLINK3_MK)
HS_TAR_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tar-conduit+=	hs-tar-conduit>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-tar-conduit+=	hs-tar-conduit>=0.4.1
BUILDLINK_PKGSRCDIR.hs-tar-conduit?=	../../archivers/hs-tar-conduit

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.endif	# HS_TAR_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tar-conduit
