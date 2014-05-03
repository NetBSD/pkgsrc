# $NetBSD: buildlink3.mk,v 1.1 2014/05/03 19:03:39 wiz Exp $

BUILDLINK_TREE+=	libisoburn

.if !defined(LIBISOBURN_BUILDLINK3_MK)
LIBISOBURN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libisoburn+=	libisoburn>=1.1.8
BUILDLINK_PKGSRCDIR.libisoburn?=	../../sysutils/libisoburn

.include "../../sysutils/libisofs/buildlink3.mk"
.include "../../sysutils/libburn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBISOBURN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libisoburn
