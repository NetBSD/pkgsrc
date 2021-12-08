# $NetBSD: buildlink3.mk,v 1.3 2021/12/08 16:01:59 adam Exp $

BUILDLINK_TREE+=	liblangtag

.if !defined(LIBLANGTAG_BUILDLINK3_MK)
LIBLANGTAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblangtag+=	liblangtag>=0.4.0
BUILDLINK_ABI_DEPENDS.liblangtag?=	liblangtag>=0.6.3nb4
BUILDLINK_PKGSRCDIR.liblangtag?=	../../devel/liblangtag

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBLANGTAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblangtag
