# $NetBSD: buildlink3.mk,v 1.1 2020/11/22 11:58:58 nia Exp $

BUILDLINK_TREE+=	libpwquality

.if !defined(LIBPWQUALITY_BUILDLINK3_MK)
LIBPWQUALITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpwquality+=	libpwquality>=1.3.0
BUILDLINK_PKGSRCDIR.libpwquality?=	../../security/libpwquality

.include "../../security/cracklib/buildlink3.mk"
.endif	# LIBPWQUALITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpwquality
