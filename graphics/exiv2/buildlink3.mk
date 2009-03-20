# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:38 joerg Exp $

BUILDLINK_TREE+=	exiv2

.if !defined(EXIV2_BUILDLINK3_MK)
EXIV2_BUILDLINK3_MK:=

# 0.18 changes the signature of printTag
BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.18
BUILDLINK_ABI_DEPENDS.exiv2+=	exiv2>=0.18
BUILDLINK_PKGSRCDIR.exiv2?=	../../graphics/exiv2
.endif # EXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-exiv2
