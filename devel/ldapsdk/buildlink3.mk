# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:15 joerg Exp $

BUILDLINK_TREE+=	ldapsdk

.if !defined(LDAPSDK_BUILDLINK3_MK)
LDAPSDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldapsdk+=	ldapsdk>=12311998
BUILDLINK_ABI_DEPENDS.ldapsdk?=	ldapsdk>=12311998nb2
BUILDLINK_PKGSRCDIR.ldapsdk?=	../../devel/ldapsdk
.endif # LDAPSDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldapsdk
