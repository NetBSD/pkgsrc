# $NetBSD: buildlink3.mk,v 1.1 2018/10/07 12:53:54 schmonz Exp $

BUILDLINK_TREE+=	fehqlibs

.if !defined(FEHQLIBS_BUILDLINK3_MK)
FEHQLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fehqlibs+=fehqlibs>=0.9
BUILDLINK_PKGSRCDIR.fehqlibs?=	../../net/fehqlibs
BUILDLINK_DEPMETHOD.fehqlibs?=	build
.endif	# FEHQLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fehqlibs
