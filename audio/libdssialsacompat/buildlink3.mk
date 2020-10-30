# $NetBSD: buildlink3.mk,v 1.1 2020/10/30 15:22:23 nia Exp $

BUILDLINK_TREE+=	libdssialsacompat

.if !defined(LIBDSSIALSACOMPAT_BUILDLINK3_MK)
LIBDSSIALSACOMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdssialsacompat+=	libdssialsacompat>=1.0.8a
BUILDLINK_PKGSRCDIR.libdssialsacompat?=		../../audio/libdssialsacompat
BUILDLINK_INCDIRS.libdssialsacompat?=		include/dssi
.endif # LIBDSSIALSACOMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdssialsacompat
