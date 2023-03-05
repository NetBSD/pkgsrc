# $NetBSD: buildlink3.mk,v 1.3 2023/03/05 20:19:11 wiz Exp $

BUILDLINK_TREE+=	polyml

.if !defined(POLYML_BUILDLINK3_MK)
POLYML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polyml+=	polyml>=5.8.1
BUILDLINK_ABI_DEPENDS.polyml+=	polyml>=5.8.1
BUILDLINK_PKGSRCDIR.polyml?=	../../lang/polyml
.endif	# POLYML_BUILDLINK3_MK

BUILDLINK_TREE+=	-polyml
