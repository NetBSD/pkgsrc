# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:30 joerg Exp $

BUILDLINK_TREE+=	liblinebreak

.if !defined(LIBLINEBREAK_BUILDLINK3_MK)
LIBLINEBREAK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblinebreak+=	liblinebreak>=1.0
BUILDLINK_PKGSRCDIR.liblinebreak?=	../../textproc/liblinebreak
.endif # LIBLINEBREAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblinebreak
