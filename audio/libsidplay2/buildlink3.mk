# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:23:56 joerg Exp $

BUILDLINK_TREE+=	libsidplay2

.if !defined(LIBSIDPLAY2_BUILDLINK3_MK)
LIBSIDPLAY2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsidplay2+=	libsidplay2>=2.0.9
BUILDLINK_PKGSRCDIR.libsidplay2?=	../../audio/libsidplay2
.endif # LIBSIDPLAY2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsidplay2
