# $NetBSD: buildlink3.mk,v 1.1 2021/02/19 18:01:39 nros Exp $

BUILDLINK_TREE+=	dav1d

.if !defined(DAV1D_BUILDLINK3_MK)
DAV1D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dav1d+=	dav1d>=0.8.1
BUILDLINK_PKGSRCDIR.dav1d?=	../../multimedia/dav1d
.endif	# DAV1D_BUILDLINK3_MK

BUILDLINK_TREE+=	-dav1d
