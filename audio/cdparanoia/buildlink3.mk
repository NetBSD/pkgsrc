# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:23:52 joerg Exp $

BUILDLINK_TREE+=	cdparanoia

.if !defined(CDPARANOIA_BUILDLINK3_MK)
CDPARANOIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdparanoia+=		cdparanoia>=3.0
BUILDLINK_ABI_DEPENDS.cdparanoia?=	cdparanoia>=3.0.9.8nb5
BUILDLINK_PKGSRCDIR.cdparanoia?=	../../audio/cdparanoia
.endif # CDPARANOIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdparanoia
