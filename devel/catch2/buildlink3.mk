# $NetBSD: buildlink3.mk,v 1.1 2020/02/03 12:35:13 bsiegert Exp $

BUILDLINK_TREE+=	catch2

.if !defined(CATCH2_BUILDLINK3_MK)
CATCH2_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.catch2?=	build
BUILDLINK_API_DEPENDS.catch2+=	catch2>=2.11.1
BUILDLINK_PKGSRCDIR.catch2?=	../../devel/catch2
.endif	# CATCH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-catch2
