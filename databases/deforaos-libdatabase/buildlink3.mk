# $NetBSD: buildlink3.mk,v 1.2 2015/08/31 22:24:05 khorben Exp $

BUILDLINK_TREE+=	deforaos-libdatabase

.if !defined(DEFORAOS_LIBDATABASE_BUILDLINK3_MK)
DEFORAOS_LIBDATABASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libdatabase+=	deforaos-libdatabase>=0.0.1
BUILDLINK_PKGSRCDIR.deforaos-libdatabase?=	../../databases/deforaos-libdatabase

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.endif	# DEFORAOS_LIBDATABASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libdatabase
