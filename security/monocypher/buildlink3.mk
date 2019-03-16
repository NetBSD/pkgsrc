# $NetBSD: buildlink3.mk,v 1.1 2019/03/16 09:17:09 maya Exp $

BUILDLINK_TREE+=	monocypher

.if !defined(MONOCYPHER_BUILDLINK3_MK)
MONOCYPHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.monocypher+=	monocypher>=2.0.5
BUILDLINK_PKGSRCDIR.monocypher?=	../../security/monocypher
.endif	# MONOCYPHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-monocypher
