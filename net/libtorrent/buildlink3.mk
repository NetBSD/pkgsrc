# $NetBSD: buildlink3.mk,v 1.29 2025/10/05 19:26:11 js Exp $

BUILDLINK_TREE+=	libtorrent

.if !defined(LIBTORRENT_BUILDLINK3_MK)
LIBTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent+=	libtorrent>=0.14.0
BUILDLINK_ABI_DEPENDS.libtorrent+=	libtorrent>=0.16.0nb1
BUILDLINK_PKGSRCDIR.libtorrent?=	../../net/libtorrent

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # LIBTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent
