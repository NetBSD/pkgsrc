# $NetBSD: buildlink3.mk,v 1.28 2025/09/07 07:49:15 adam Exp $

BUILDLINK_TREE+=	libtorrent

.if !defined(LIBTORRENT_BUILDLINK3_MK)
LIBTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent+=	libtorrent>=0.14.0
BUILDLINK_ABI_DEPENDS.libtorrent+=	libtorrent>=0.14.0
BUILDLINK_PKGSRCDIR.libtorrent?=	../../net/libtorrent

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # LIBTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent
