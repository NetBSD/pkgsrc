# $NetBSD: buildlink3.mk,v 1.1 2025/01/29 16:28:05 pho Exp $

BUILDLINK_TREE+=	hs-directory-ospath-streaming

.if !defined(HS_DIRECTORY_OSPATH_STREAMING_BUILDLINK3_MK)
HS_DIRECTORY_OSPATH_STREAMING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-directory-ospath-streaming+=	hs-directory-ospath-streaming>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-directory-ospath-streaming+=	hs-directory-ospath-streaming>=0.2.1
BUILDLINK_PKGSRCDIR.hs-directory-ospath-streaming?=	../../sysutils/hs-directory-ospath-streaming

.include "../../devel/hs-atomic-counter/buildlink3.mk"
.endif	# HS_DIRECTORY_OSPATH_STREAMING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-directory-ospath-streaming
