# $NetBSD: buildlink3.mk,v 1.14 2014/10/07 16:47:13 adam Exp $

BUILDLINK_TREE+=	monotorrent

.if !defined(MONOTORRENT_BUILDLINK3_MK)
MONOTORRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.monotorrent+=	monotorrent>=0.72
BUILDLINK_ABI_DEPENDS.monotorrent+=	monotorrent>=0.72nb10
BUILDLINK_PKGSRCDIR.monotorrent?=	../../net/monotorrent

.include "../../lang/mono2/buildlink3.mk"
.endif # MONOTORRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-monotorrent
