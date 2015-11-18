# $NetBSD: buildlink3.mk,v 1.9 2015/11/18 14:19:47 ryoon Exp $
#

BUILDLINK_TREE+=	libdlna

.if !defined(LIBDLNA_BUILDLINK3_MK)
LIBDLNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdlna+=	libdlna>=0.2.3
BUILDLINK_ABI_DEPENDS.libdlna+=	libdlna>=0.2.4nb5
BUILDLINK_PKGSRCDIR.libdlna?=	../../net/libdlna

.include "../../multimedia/ffmpeg1/buildlink3.mk"
.endif	# LIBDLNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdlna
