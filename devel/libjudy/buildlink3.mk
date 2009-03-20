# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:19 joerg Exp $

BUILDLINK_TREE+=	libjudy

.if !defined(LIBJUDY_BUILDLINK3_MK)
LIBJUDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjudy+=	libjudy>=1.0.3
BUILDLINK_PKGSRCDIR.libjudy?=	../../devel/libjudy
.endif # LIBJUDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjudy
