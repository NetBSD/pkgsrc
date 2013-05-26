# $NetBSD: buildlink3.mk,v 1.1 2013/05/26 22:59:06 rodent Exp $

BUILDLINK_TREE+=	libticonv

.if !defined(LIBTICONV_BUILDLINK3_MK)
LIBTICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticonv+=	libticonv>=1.1.3
BUILDLINK_PKGSRCDIR.libticonv?=	../../comms/libticonv

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBTICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticonv
