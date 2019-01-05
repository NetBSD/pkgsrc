# $NetBSD: buildlink3.mk,v 1.1 2019/01/05 06:16:14 schmonz Exp $

BUILDLINK_TREE+=	nacl

.if !defined(NACL_BUILDLINK3_MK)
NACL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nacl+=	nacl>=20110221
BUILDLINK_PKGSRCDIR.nacl?=	../../security/nacl
BUILDLINK_DEPMETHOD.nacl?=	build
.endif	# NACL_BUILDLINK3_MK

BUILDLINK_TREE+=	-nacl
