# $NetBSD: buildlink3.mk,v 1.11 2015/11/23 09:51:48 wiz Exp $

BUILDLINK_TREE+=	libshout

.if !defined(LIBSHOUT_BUILDLINK3_MK)
LIBSHOUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libshout+=	libshout>=2.0
BUILDLINK_ABI_DEPENDS.libshout+=	libshout>=2.0nb1
BUILDLINK_PKGSRCDIR.libshout?=	../../audio/libshout

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBSHOUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libshout
