# $NetBSD: buildlink3.mk,v 1.2 2026/11/11 11:55:29 wiz Exp $

BUILDLINK_TREE+=	libtatsu

.if !defined(LIBTATSU_BUILDLINK3_MK)
LIBTATSU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtatsu+=	libtatsu>=1.0.5
BUILDLINK_ABI_DEPENDS.libtatsu?=		libtatsu>=1.1.0nb1
BUILDLINK_PKGSRCDIR.libtatsu?=		../../security/libtatsu

.include "../../textproc/libplist/buildlink3.mk"
.endif	# LIBTATSU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtatsu
