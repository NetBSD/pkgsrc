# $NetBSD: buildlink3.mk,v 1.8 2020/01/18 21:48:07 jperkin Exp $

BUILDLINK_TREE+=	libthrift

.if !defined(LIBTHRIFT_BUILDLINK3_MK)
LIBTHRIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libthrift+=	libthrift>=0.2.0
BUILDLINK_ABI_DEPENDS.libthrift+=	libthrift>=0.13.0nb2
BUILDLINK_PKGSRCDIR.libthrift?=		../../devel/libthrift

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # LIBTHRIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libthrift
