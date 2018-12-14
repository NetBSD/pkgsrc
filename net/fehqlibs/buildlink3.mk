# $NetBSD: buildlink3.mk,v 1.2 2018/12/14 22:51:32 schmonz Exp $

BUILDLINK_TREE+=	fehqlibs

.if !defined(FEHQLIBS_BUILDLINK3_MK)
FEHQLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fehqlibs+=fehqlibs>=0.9.10
BUILDLINK_PKGSRCDIR.fehqlibs?=	../../net/fehqlibs
BUILDLINK_DEPMETHOD.fehqlibs?=	build
.endif	# FEHQLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fehqlibs
