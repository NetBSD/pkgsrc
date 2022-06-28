# $NetBSD: buildlink3.mk,v 1.9 2022/06/28 11:31:46 wiz Exp $

BUILDLINK_TREE+=	ldapsdk

.if !defined(LDAPSDK_BUILDLINK3_MK)
LDAPSDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldapsdk+=	ldapsdk>=12311998
BUILDLINK_ABI_DEPENDS.ldapsdk+=	ldapsdk>=12311998nb12
BUILDLINK_PKGSRCDIR.ldapsdk?=	../../devel/ldapsdk
.endif # LDAPSDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldapsdk
