# $NetBSD: buildlink3.mk,v 1.1 2023/11/02 01:55:07 pho Exp $

BUILDLINK_TREE+=	hs-torrent

.if !defined(HS_TORRENT_BUILDLINK3_MK)
HS_TORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-torrent+=	hs-torrent>=10000.1.3
BUILDLINK_ABI_DEPENDS.hs-torrent+=	hs-torrent>=10000.1.3
BUILDLINK_PKGSRCDIR.hs-torrent?=	../../net/hs-torrent

.include "../../converters/hs-bencode/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_TORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-torrent
