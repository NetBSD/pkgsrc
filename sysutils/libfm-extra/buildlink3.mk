# $NetBSD: buildlink3.mk,v 1.1 2016/05/22 22:08:40 youri Exp $

BUILDLINK_TREE+=	libfm-extra

.if !defined(LIBFM_EXTRA_BUILDLINK3_MK)
LIBFM_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm-extra+=	libfm-extra>=1.2.4
BUILDLINK_PKGSRCDIR.libfm-extra?=	../../sysutils/libfm-extra

.endif	# LIBFM-EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm-extra
