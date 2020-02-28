# $NetBSD: buildlink3.mk,v 1.1 2020/02/28 22:08:05 plunky Exp $

BUILDLINK_TREE+=	congen

.if !defined(CONGEN_BUILDLINK3_MK)
CONGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.congen+=	congen>=1.7
BUILDLINK_PKGSRCDIR.congen?=	../../math/congen

.endif	# CONGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-congen
