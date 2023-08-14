# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:10 wiz Exp $

BUILDLINK_TREE+=	libpwquality

.if !defined(LIBPWQUALITY_BUILDLINK3_MK)
LIBPWQUALITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpwquality+=	libpwquality>=1.3.0
BUILDLINK_ABI_DEPENDS.libpwquality?=	libpwquality>=1.4.4nb1
BUILDLINK_PKGSRCDIR.libpwquality?=	../../security/libpwquality

.include "../../security/cracklib/buildlink3.mk"
.endif	# LIBPWQUALITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpwquality
