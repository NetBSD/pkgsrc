# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:05 wiz Exp $

BUILDLINK_TREE+=	ctemplate

.if !defined(CTEMPLATE_BUILDLINK3_MK)
CTEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ctemplate+=	ctemplate>=0.97
BUILDLINK_ABI_DEPENDS.ctemplate?=		ctemplate>=2.3nb10
BUILDLINK_PKGSRCDIR.ctemplate?=		../../devel/ctemplate

.include "../../mk/pthread.buildlink3.mk"
.endif # CTEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ctemplate
