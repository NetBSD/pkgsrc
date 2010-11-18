# $NetBSD: buildlink3.mk,v 1.1 2010/11/18 10:39:19 wiz Exp $

BUILDLINK_TREE+=	libwpg

.if !defined(LIBWPG_BUILDLINK3_MK)
LIBWPG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwpg+=	libwpg>=0.1.3
BUILDLINK_PKGSRCDIR.libwpg?=	../../converters/libwpg

.include "../../converters/libwpd/buildlink3.mk"
.endif	# LIBWPG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwpg
