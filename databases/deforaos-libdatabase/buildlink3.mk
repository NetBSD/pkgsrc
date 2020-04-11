# $NetBSD: buildlink3.mk,v 1.3 2020/04/11 03:57:10 khorben Exp $

BUILDLINK_TREE+=	deforaos-libdatabase

.if !defined(DEFORAOS_LIBDATABASE_BUILDLINK3_MK)
DEFORAOS_LIBDATABASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libdatabase+=	deforaos-libdatabase>=0.0.2
BUILDLINK_PKGSRCDIR.deforaos-libdatabase?=	../../databases/deforaos-libdatabase

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.endif	# DEFORAOS_LIBDATABASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libdatabase
