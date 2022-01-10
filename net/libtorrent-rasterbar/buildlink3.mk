# $NetBSD: buildlink3.mk,v 1.9 2022/01/10 01:46:42 ryoon Exp $

BUILDLINK_TREE+=	libtorrent-rasterbar

.if !defined(LIBTORRENT_RASTERBAR_BUILDLINK3_MK)
LIBTORRENT_RASTERBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtorrent-rasterbar+=	libtorrent-rasterbar>=1.2.2
BUILDLINK_ABI_DEPENDS.libtorrent-rasterbar+=	libtorrent-rasterbar>=1.2.15nb1
BUILDLINK_PKGSRCDIR.libtorrent-rasterbar?=	../../net/libtorrent-rasterbar

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBTORRENT_RASTERBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtorrent-rasterbar
