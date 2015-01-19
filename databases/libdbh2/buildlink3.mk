# $NetBSD: buildlink3.mk,v 1.1 2015/01/19 02:07:41 mef Exp $

BUILDLINK_TREE+=	libdbh2

.if !defined(LIBDBH2_BUILDLINK3_MK)
LIBDBH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbh2+=		libdbh2>=5.0.16
BUILDLINK_PKGSRCDIR.libdbh2?=	../../databases/libdbh2
.endif # LIBDBH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbh2
