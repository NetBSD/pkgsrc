# $NetBSD: buildlink3.mk,v 1.3 2026/11/15 19:45:00 wiz Exp $

BUILDLINK_TREE+=	libtatsu

.if !defined(LIBTATSU_BUILDLINK3_MK)
LIBTATSU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtatsu+=	libtatsu>=1.0.5
BUILDLINK_ABI_DEPENDS.libtatsu?=	libtatsu>=1.1.0nb1
BUILDLINK_PKGSRCDIR.libtatsu?=		../../security/libtatsu

.include "../../textproc/libplist/buildlink3.mk"
.endif	# LIBTATSU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtatsu
