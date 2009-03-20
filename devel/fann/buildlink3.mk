# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:12 joerg Exp $

BUILDLINK_TREE+=	fann

.if !defined(FANN_BUILDLINK3_MK)
FANN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fann+=	fann>=2.0.0
BUILDLINK_PKGSRCDIR.fann?=	../../devel/fann
.endif # FANN_BUILDLINK3_MK

BUILDLINK_TREE+=	-fann
