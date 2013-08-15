# $NetBSD: buildlink3.mk,v 1.1 2013/08/15 17:12:12 joerg Exp $

BUILDLINK_TREE+=	open-vcdiff

.if !defined(OPEN_VCDIFF_BUILDLINK3_MK)
OPEN_VCDIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.open-vcdiff+=	open-vcdiff>=0.8.3
BUILDLINK_PKGSRCDIR.open-vcdiff?=	../../devel/open-vcdiff
.endif	# OPEN_VCDIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-open-vcdiff
