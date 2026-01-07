# $NetBSD: buildlink3.mk,v 1.47 2026/01/07 08:48:50 wiz Exp $

BUILDLINK_TREE+=	efreet

.if !defined(EFREET_BUILDLINK3_MK)
EFREET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efreet+=	efreet>=1.7.10
BUILDLINK_ABI_DEPENDS.efreet?=	efreet>=1.7.10nb23
BUILDLINK_PKGSRCDIR.efreet?=	../../sysutils/efreet

.include        "../../devel/ecore/buildlink3.mk"
.endif # EFREET_BUILDLINK3_MK

BUILDLINK_TREE+=	-efreet
