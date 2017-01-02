# $NetBSD: buildlink3.mk,v 1.14 2017/01/02 02:18:30 schmonz Exp $

BUILDLINK_TREE+=	bglibs

.if !defined(BGLIBS_BUILDLINK3_MK)
BGLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bglibs+=	bglibs>=2.03
BUILDLINK_PKGSRCDIR.bglibs?=	../../devel/bglibs
.endif # BGLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-bglibs
