# $NetBSD: buildlink3.mk,v 1.1 2019/06/12 19:32:44 alnsn Exp $

BUILDLINK_TREE+=	polyml

.if !defined(POLYML_BUILDLINK3_MK)
POLYML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polyml+=	polyml>=5.7.1
BUILDLINK_ABI_DEPENDS.polyml+=	polyml>=5.7.1
BUILDLINK_PKGSRCDIR.polyml?=	../../lang/polyml
.endif	# POLYML_BUILDLINK3_MK

BUILDLINK_TREE+=	-polyml

