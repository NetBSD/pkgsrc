# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:23:55 joerg Exp $

BUILDLINK_TREE+=	libdiscid

.if !defined(LIBDISCID_BUILDLINK3_MK)
LIBDISCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdiscid+=	libdiscid>=0.1.0
BUILDLINK_PKGSRCDIR.libdiscid?=	../../audio/libdiscid
.endif # LIBDISCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdiscid
