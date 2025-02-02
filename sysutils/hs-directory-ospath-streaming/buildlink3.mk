# $NetBSD: buildlink3.mk,v 1.2 2025/02/02 13:05:46 pho Exp $

BUILDLINK_TREE+=	hs-directory-ospath-streaming

.if !defined(HS_DIRECTORY_OSPATH_STREAMING_BUILDLINK3_MK)
HS_DIRECTORY_OSPATH_STREAMING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-directory-ospath-streaming+=	hs-directory-ospath-streaming>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-directory-ospath-streaming+=	hs-directory-ospath-streaming>=0.2.1nb1
BUILDLINK_PKGSRCDIR.hs-directory-ospath-streaming?=	../../sysutils/hs-directory-ospath-streaming

.include "../../devel/hs-atomic-counter/buildlink3.mk"
.endif	# HS_DIRECTORY_OSPATH_STREAMING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-directory-ospath-streaming
