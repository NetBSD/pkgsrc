# $NetBSD: buildlink3.mk,v 1.11 2012/03/03 00:11:54 wiz Exp $

BUILDLINK_TREE+=	gob2

.if !defined(GOB2_BUILDLINK3_MK)
GOB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gob2+=	gob2>=2.0.10
BUILDLINK_ABI_DEPENDS.gob2?=	gob2>=2.0.18nb4
BUILDLINK_PKGSRCDIR.gob2?=	../../devel/gob2

#.include "../../devel/glib2/buildlink3.mk"
.endif # GOB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gob2
