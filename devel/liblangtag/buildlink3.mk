# $NetBSD: buildlink3.mk,v 1.1 2013/08/24 16:15:10 jaapb Exp $

BUILDLINK_TREE+=	liblangtag

.if !defined(LIBLANGTAG_BUILDLINK3_MK)
LIBLANGTAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblangtag+=	liblangtag>=0.4.0
BUILDLINK_PKGSRCDIR.liblangtag?=	../../devel/liblangtag

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBLANGTAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblangtag
