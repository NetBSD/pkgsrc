# $NetBSD: buildlink3.mk,v 1.48 2026/02/06 10:05:53 wiz Exp $

BUILDLINK_TREE+=	efreet

.if !defined(EFREET_BUILDLINK3_MK)
EFREET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efreet+=	efreet>=1.7.10
BUILDLINK_ABI_DEPENDS.efreet?=	efreet>=1.7.10nb24
BUILDLINK_PKGSRCDIR.efreet?=	../../sysutils/efreet

.include        "../../devel/ecore/buildlink3.mk"
.endif # EFREET_BUILDLINK3_MK

BUILDLINK_TREE+=	-efreet
