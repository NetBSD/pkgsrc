# $NetBSD: buildlink3.mk,v 1.1 2014/12/01 00:05:38 obache Exp $
#

BUILDLINK_TREE+=	opencc

.if !defined(OPENCC_BUILDLINK3_MK)
OPENCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencc+=	opencc>=0.4.2
BUILDLINK_PKGSRCDIR.opencc?=	../../converters/opencc
.endif	# OPENCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencc
