# $NetBSD: buildlink3.mk,v 1.1 2021/01/24 19:09:21 maya Exp $

BUILDLINK_TREE+=	libstubborn

.if !defined(LIBSTUBBORN_BUILDLINK3_MK)
LIBSTUBBORN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstubborn+=	libstubborn>=0.1
BUILDLINK_PKGSRCDIR.libstubborn?=	../../devel/libstubborn
.endif	# LIBSTUBBORN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstubborn
