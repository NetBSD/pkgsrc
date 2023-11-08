# $NetBSD: buildlink3.mk,v 1.33 2023/11/08 13:20:31 wiz Exp $

BUILDLINK_TREE+=	monotorrent

.if !defined(MONOTORRENT_BUILDLINK3_MK)
MONOTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.monotorrent+=	monotorrent>=0.72
BUILDLINK_ABI_DEPENDS.monotorrent+=	monotorrent>=0.72nb31
BUILDLINK_PKGSRCDIR.monotorrent?=	../../net/monotorrent

.include "../../lang/mono/buildlink3.mk"
.endif # MONOTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-monotorrent
