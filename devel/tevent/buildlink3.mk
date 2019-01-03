# $NetBSD: buildlink3.mk,v 1.1 2019/01/03 19:30:47 adam Exp $

BUILDLINK_TREE+=	tevent

.if !defined(TEVENT_BUILDLINK3_MK)
TEVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tevent+=	tevent>=0.9.37
BUILDLINK_PKGSRCDIR.tevent?=	../../devel/tevent

.include "../../devel/talloc/buildlink3.mk"
.endif	# TEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tevent
