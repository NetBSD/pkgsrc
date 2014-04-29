# $NetBSD: buildlink3.mk,v 1.1 2014/04/29 19:59:44 wiz Exp $

BUILDLINK_TREE+=	libburn

.if !defined(LIBBURN_BUILDLINK3_MK)
LIBBURN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libburn+=	libburn>=1.1.8
BUILDLINK_PKGSRCDIR.libburn?=	../../sysutils/libburn
.endif	# LIBBURN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libburn
