# $NetBSD: buildlink3.mk,v 1.3 2012/03/12 07:07:03 sbd Exp $

BUILDLINK_TREE+=	libthrift

.if !defined(LIBTHRIFT_BUILDLINK3_MK)
LIBTHRIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libthrift+=	libthrift>=0.2.0
BUILDLINK_ABI_DEPENDS.libthrift+=	libthrift>=0.5.0nb1
BUILDLINK_PKGSRCDIR.libthrift?=		../../devel/libthrift

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"

.endif # LIBTHRIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libthrift
