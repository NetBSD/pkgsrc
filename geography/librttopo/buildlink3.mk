# $NetBSD: buildlink3.mk,v 1.1 2023/02/15 13:05:48 wiz Exp $

BUILDLINK_TREE+=	librttopo

.if !defined(LIBRTTOPO_BUILDLINK3_MK)
LIBRTTOPO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librttopo+=	librttopo>=1.1.0
BUILDLINK_PKGSRCDIR.librttopo?=		../../geography/librttopo

.include "../../geography/geos/buildlink3.mk"
.endif	# LIBRTTOPO_BUILDLINK3_MK

BUILDLINK_TREE+=	-librttopo
