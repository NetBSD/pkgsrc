# $NetBSD: buildlink3.mk,v 1.11 2020/01/12 20:19:55 ryoon Exp $

BUILDLINK_TREE+=	gearmand

.if !defined(GEARMAND_BUILDLINK3_MK)
GEARMAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gearmand+=	gearmand>=1.0.6nb17
BUILDLINK_ABI_DEPENDS.gearmand+=	gearmand>=1.1.18nb7
BUILDLINK_PKGSRCDIR.gearmand?=		../../devel/gearmand

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# GEARMAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-gearmand
