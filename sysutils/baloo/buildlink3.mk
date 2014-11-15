# $NetBSD: buildlink3.mk,v 1.2 2014/11/15 20:49:56 markd Exp $

BUILDLINK_TREE+=	baloo

.if !defined(BALOO_BUILDLINK3_MK)
BALOO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo+=	baloo>=4.14.3
BUILDLINK_PKGSRCDIR.baloo?=	../../sysutils/baloo

.include "../../sysutils/kfilemetadata/buildlink3.mk"
.endif	# BALOO_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo
