# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:18 pho Exp $

BUILDLINK_TREE+=	hs-torrent

.if !defined(HS_TORRENT_BUILDLINK3_MK)
HS_TORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-torrent+=	hs-torrent>=10000.1.3
BUILDLINK_ABI_DEPENDS.hs-torrent+=	hs-torrent>=10000.1.3nb1
BUILDLINK_PKGSRCDIR.hs-torrent?=	../../net/hs-torrent

.include "../../converters/hs-bencode/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_TORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-torrent
