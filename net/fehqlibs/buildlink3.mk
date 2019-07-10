# $NetBSD: buildlink3.mk,v 1.3 2019/07/10 11:20:02 schmonz Exp $

BUILDLINK_TREE+=	fehqlibs

.if !defined(FEHQLIBS_BUILDLINK3_MK)
FEHQLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fehqlibs+=fehqlibs>=0.9.12.10
BUILDLINK_PKGSRCDIR.fehqlibs?=	../../net/fehqlibs
.endif	# FEHQLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fehqlibs
