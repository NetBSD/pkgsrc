# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/12 12:32:09 adam Exp $

BUILDLINK_TREE+=	ctemplate

.if !defined(CTEMPLATE_BUILDLINK3_MK)
CTEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ctemplate+=	ctemplate>=0.97
BUILDLINK_PKGSRCDIR.ctemplate?=		../../devel/ctemplate
.endif # CTEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ctemplate
