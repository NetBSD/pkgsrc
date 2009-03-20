# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:17 joerg Exp $

BUILDLINK_TREE+=	libetm

.if !defined(LIBETM_BUILDLINK3_MK)
LIBETM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libetm+=	libetm>=1.09
BUILDLINK_PKGSRCDIR.libetm?=	../../devel/libetm
BUILDLINK_DEPMETHOD.libetm?=	build
.endif # LIBETM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libetm
