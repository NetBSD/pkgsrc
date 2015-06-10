# $NetBSD: buildlink3.mk,v 1.1 2015/06/10 20:37:57 pettai Exp $

BUILDLINK_TREE+=	libewf

.if !defined(LIBEWF_BUILDLINK3_MK)
LIBEWF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libewf+=	libewf>=20150126
BUILDLINK_PKGSRCDIR.libewf?=	../../devel/libewf

.endif	# LIBEWF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libewf
