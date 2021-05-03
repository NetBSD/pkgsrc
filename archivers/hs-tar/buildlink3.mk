# $NetBSD: buildlink3.mk,v 1.2 2021/05/03 19:00:52 pho Exp $

BUILDLINK_TREE+=	hs-tar

.if !defined(HS_TAR_BUILDLINK3_MK)
HS_TAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tar+=	hs-tar>=0.5.1
BUILDLINK_ABI_DEPENDS.hs-tar+=	hs-tar>=0.5.1.1nb1
BUILDLINK_PKGSRCDIR.hs-tar?=	../../archivers/hs-tar
.endif	# HS_TAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tar
