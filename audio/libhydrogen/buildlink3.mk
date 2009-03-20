# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:23:55 joerg Exp $

BUILDLINK_TREE+=	libhydrogen

.if !defined(LIBHYDROGEN_BUILDLINK3_MK)
LIBHYDROGEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhydrogen+=		libhydrogen>=0.8.0
BUILDLINK_ABI_DEPENDS.libhydrogen+=	libhydrogen>=0.8.0nb2
BUILDLINK_PKGSRCDIR.libhydrogen?=	../../audio/libhydrogen

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBHYDROGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhydrogen
