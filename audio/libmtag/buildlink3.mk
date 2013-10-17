# $NetBSD: buildlink3.mk,v 1.2 2013/10/17 07:56:40 wiz Exp $

BUILDLINK_TREE+=	libmtag

.if !defined(LIBMTAG_BUILDLINK3_MK)
LIBMTAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmtag+=	libmtag>=0.2.0
BUILDLINK_ABI_DEPENDS.libmtag?=	libmtag>=0.3.2nb1
BUILDLINK_PKGSRCDIR.libmtag?=	../../audio/libmtag

.include "../../audio/taglib/buildlink3.mk"
.endif	# LIBMTAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmtag
