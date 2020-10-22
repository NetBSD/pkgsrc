#	$NetBSD: buildlink3.mk,v 1.2 2020/10/22 20:29:44 tnn Exp $

BUILDLINK_TREE+=	libfido2

.if !defined(LIBFIDO2_BUILDLINK_MK)
LIBFIDO2_BUILDLINK_MK:=

BUILDLINK_API_DEPENDS.libfido2+=	libfido2>=1.4.0
BUILDLINK_ABI_DEPENDS.libfido2+=	libfido2>=1.5.0
BUILDLINK_PKGSRCDIR.libfido2?=		../../security/libfido2

.endif # LIBFIDO2_BUILDLINK_MK

BUILDLINK_TREE+=	-libfido2
