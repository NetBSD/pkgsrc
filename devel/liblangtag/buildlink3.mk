# $NetBSD: buildlink3.mk,v 1.6 2026/09/27 11:35:42 tnn Exp $

BUILDLINK_TREE+=	liblangtag

.if !defined(LIBLANGTAG_BUILDLINK3_MK)
LIBLANGTAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblangtag+=	liblangtag>=0.4.0
BUILDLINK_ABI_DEPENDS.liblangtag?=	liblangtag>=0.6.8nb3
BUILDLINK_PKGSRCDIR.liblangtag?=	../../devel/liblangtag

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBLANGTAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblangtag
