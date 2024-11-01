# $NetBSD: buildlink3.mk,v 1.13 2024/11/01 00:51:30 wiz Exp $

BUILDLINK_TREE+=	librelp

.if !defined(LIBRELP_BUILDLINK3_MK)
LIBRELP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librelp+=	librelp>=1.2.12
BUILDLINK_ABI_DEPENDS.librelp?=	librelp>=1.2.16nb13
BUILDLINK_PKGSRCDIR.librelp?=	../../devel/librelp

.include "../../security/gnutls/buildlink3.mk"
.endif	# LIBRELP_BUILDLINK3_MK

BUILDLINK_TREE+=	-librelp
