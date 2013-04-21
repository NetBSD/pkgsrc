# $NetBSD: buildlink3.mk,v 1.2 2013/04/21 11:23:38 rodent Exp $

BUILDLINK_TREE+=	ctemplate

.if !defined(CTEMPLATE_BUILDLINK3_MK)
CTEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ctemplate+=	ctemplate>=0.97
BUILDLINK_PKGSRCDIR.ctemplate?=		../../devel/ctemplate

.include "../../mk/pthread.buildlink3.mk"
.endif # CTEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ctemplate
