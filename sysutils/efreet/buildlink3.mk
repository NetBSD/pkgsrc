# $NetBSD: buildlink3.mk,v 1.10 2016/03/05 11:27:55 jperkin Exp $

BUILDLINK_TREE+=	efreet

.if !defined(EFREET_BUILDLINK3_MK)
EFREET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efreet+=	efreet>=1.7.7
BUILDLINK_ABI_DEPENDS.efreet?=	efreet>=1.7.7nb2
BUILDLINK_PKGSRCDIR.efreet?=	../../sysutils/efreet

.include        "../../devel/ecore/buildlink3.mk"
.endif # EFREET_BUILDLINK3_MK

BUILDLINK_TREE+=	-efreet
