# $NetBSD: buildlink3.mk,v 1.31 2026/02/06 10:05:34 wiz Exp $

BUILDLINK_TREE+=	libtorrent

.if !defined(LIBTORRENT_BUILDLINK3_MK)
LIBTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent+=	libtorrent>=0.14.0
BUILDLINK_ABI_DEPENDS.libtorrent+=	libtorrent>=0.16.6nb2
BUILDLINK_PKGSRCDIR.libtorrent?=	../../net/libtorrent

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # LIBTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent
