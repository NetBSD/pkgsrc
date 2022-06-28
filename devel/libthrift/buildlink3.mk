# $NetBSD: buildlink3.mk,v 1.9 2022/06/28 11:31:47 wiz Exp $

BUILDLINK_TREE+=	libthrift

.if !defined(LIBTHRIFT_BUILDLINK3_MK)
LIBTHRIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libthrift+=	libthrift>=0.2.0
BUILDLINK_ABI_DEPENDS.libthrift+=	libthrift>=0.15.0nb2
BUILDLINK_PKGSRCDIR.libthrift?=		../../devel/libthrift

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # LIBTHRIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libthrift
