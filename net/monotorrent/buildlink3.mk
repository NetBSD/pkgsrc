# $NetBSD: buildlink3.mk,v 1.18 2016/12/04 05:17:10 ryoon Exp $

BUILDLINK_TREE+=	monotorrent

.if !defined(MONOTORRENT_BUILDLINK3_MK)
MONOTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.monotorrent+=	monotorrent>=0.72
BUILDLINK_ABI_DEPENDS.monotorrent+=	monotorrent>=0.72nb15
BUILDLINK_PKGSRCDIR.monotorrent?=	../../net/monotorrent

.include "../../lang/mono/buildlink3.mk"
.endif # MONOTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-monotorrent
