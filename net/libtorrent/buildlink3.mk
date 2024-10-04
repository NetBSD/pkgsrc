# $NetBSD: buildlink3.mk,v 1.27 2024/10/04 09:00:05 adam Exp $

BUILDLINK_TREE+=	libtorrent

.if !defined(LIBTORRENT_BUILDLINK3_MK)
LIBTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent+=	libtorrent>=0.14.0
BUILDLINK_ABI_DEPENDS.libtorrent+=	libtorrent>=0.14.0
BUILDLINK_PKGSRCDIR.libtorrent?=	../../net/libtorrent

.include "../../security/openssl/buildlink3.mk"
.endif # LIBTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent
