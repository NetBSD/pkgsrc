# $NetBSD: buildlink3.mk,v 1.1 2013/12/31 23:10:21 ryoon Exp $

BUILDLINK_TREE+=	libzen

.if !defined(LIBZEN_BUILDLINK3_MK)
LIBZEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzen+=	libzen>=0.4.29
BUILDLINK_PKGSRCDIR.libzen?=	../../devel/libzen
.endif	# LIBZEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzen
