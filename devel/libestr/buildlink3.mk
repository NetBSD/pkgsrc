# $NetBSD: buildlink3.mk,v 1.2 2014/09/04 19:43:10 fhajny Exp $

BUILDLINK_TREE+=	libestr

.if !defined(LIBESTR_BUILDLINK3_MK)
LIBESTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libestr+=	libestr>=0.1.0
BUILDLINK_PKGSRCDIR.libestr?=	../../devel/libestr

.endif # LIBESTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libestr
