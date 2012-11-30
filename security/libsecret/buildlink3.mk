# $NetBSD: buildlink3.mk,v 1.1 2012/11/30 15:49:47 ryoon Exp $

BUILDLINK_TREE+=	libsecret

.if !defined(LIBSECRET_BUILDLINK3_MK)
LIBSECRET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsecret+=	libsecret>=0.12
BUILDLINK_PKGSRCDIR.libsecret?=	../../security/libsecret

.endif	# LIBSECRET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsecret
