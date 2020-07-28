# $NetBSD: buildlink3.mk,v 1.2 2020/07/28 00:06:09 gutteridge Exp $

BUILDLINK_TREE+=	libfm-extra

.if !defined(LIBFM_EXTRA_BUILDLINK3_MK)
LIBFM_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm-extra+=	libfm-extra>=1.2.4
BUILDLINK_PKGSRCDIR.libfm-extra?=	../../sysutils/libfm-extra

.endif	# LIBFM_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm-extra
