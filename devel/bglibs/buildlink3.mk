# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:10 joerg Exp $

BUILDLINK_TREE+=	bglibs

.if !defined(BGLIBS_BUILDLINK3_MK)
BGLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bglibs+=	bglibs>=1.104
BUILDLINK_PKGSRCDIR.bglibs?=	../../devel/bglibs
.endif # BGLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-bglibs
