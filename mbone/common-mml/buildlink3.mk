# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:59 joerg Exp $

BUILDLINK_TREE+=	common-mml

.if !defined(COMMON_MML_BUILDLINK3_MK)
COMMON_MML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.common-mml+=	common-mml>=1.2.14
BUILDLINK_PKGSRCDIR.common-mml?=	../../mbone/common-mml
.endif # COMMON_MML_BUILDLINK3_MK

BUILDLINK_TREE+=	-common-mml
