# $NetBSD: buildlink3.mk,v 1.34 2023/01/29 21:14:59 ryoon Exp $

BUILDLINK_TREE+=	efreet

.if !defined(EFREET_BUILDLINK3_MK)
EFREET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efreet+=	efreet>=1.7.10
BUILDLINK_ABI_DEPENDS.efreet?=	efreet>=1.7.10nb8
BUILDLINK_PKGSRCDIR.efreet?=	../../sysutils/efreet

.include        "../../devel/ecore/buildlink3.mk"
.endif # EFREET_BUILDLINK3_MK

BUILDLINK_TREE+=	-efreet
