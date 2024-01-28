# $NetBSD: buildlink3.mk,v 1.3 2024/01/28 13:24:33 wiz Exp $

BUILDLINK_TREE+=	libmtag

.if !defined(LIBMTAG_BUILDLINK3_MK)
LIBMTAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmtag+=	libmtag>=0.2.0
BUILDLINK_ABI_DEPENDS.libmtag?=	libmtag>=0.3.2nb2
BUILDLINK_PKGSRCDIR.libmtag?=	../../audio/libmtag

.include "../../audio/taglib/buildlink3.mk"
.endif	# LIBMTAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmtag
