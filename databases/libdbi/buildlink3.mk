# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/10 23:55:48 wiz Exp $

BUILDLINK_TREE+=	libdbi

.if !defined(LIBDBI_BUILDLINK3_MK)
LIBDBI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbi+=	libdbi>=0.8.3
BUILDLINK_PKGSRCDIR.libdbi?=	../../databases/libdbi
.endif # LIBDBI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbi
