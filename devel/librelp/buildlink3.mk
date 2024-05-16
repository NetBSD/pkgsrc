# $NetBSD: buildlink3.mk,v 1.12 2024/05/16 06:14:46 wiz Exp $

BUILDLINK_TREE+=	librelp

.if !defined(LIBRELP_BUILDLINK3_MK)
LIBRELP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librelp+=	librelp>=1.2.12
BUILDLINK_ABI_DEPENDS.librelp?=	librelp>=1.2.16nb11
BUILDLINK_PKGSRCDIR.librelp?=	../../devel/librelp

.include "../../security/gnutls/buildlink3.mk"
.endif	# LIBRELP_BUILDLINK3_MK

BUILDLINK_TREE+=	-librelp
