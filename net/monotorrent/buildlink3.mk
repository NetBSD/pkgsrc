# $NetBSD: buildlink3.mk,v 1.22 2018/04/14 07:34:00 adam Exp $

BUILDLINK_TREE+=	monotorrent

.if !defined(MONOTORRENT_BUILDLINK3_MK)
MONOTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.monotorrent+=	monotorrent>=0.72
BUILDLINK_ABI_DEPENDS.monotorrent+=	monotorrent>=0.72nb19
BUILDLINK_PKGSRCDIR.monotorrent?=	../../net/monotorrent

.include "../../lang/mono/buildlink3.mk"
.endif # MONOTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-monotorrent
