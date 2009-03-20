# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:11 joerg Exp $

BUILDLINK_TREE+=	openslp

.if !defined(OPENSLP_BUILDLINK3_MK)
OPENSLP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openslp+=	openslp>=1.0.1
BUILDLINK_ABI_DEPENDS.openslp+=	openslp>=1.2.1
BUILDLINK_PKGSRCDIR.openslp?=	../../net/openslp
.endif # OPENSLP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openslp
