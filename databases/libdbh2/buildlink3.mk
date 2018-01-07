# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:03:59 rillig Exp $

BUILDLINK_TREE+=	libdbh2

.if !defined(LIBDBH2_BUILDLINK3_MK)
LIBDBH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbh2+=	libdbh2>=5.0.16
BUILDLINK_PKGSRCDIR.libdbh2?=	../../databases/libdbh2
.endif # LIBDBH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbh2
