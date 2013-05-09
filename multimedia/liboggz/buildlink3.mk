# $NetBSD: buildlink3.mk,v 1.1 2013/05/09 00:40:12 rodent Exp $

BUILDLINK_TREE+=      liboggz

.if !defined(LIBOGGZ_BUILDLINK3_MK)
LIBOGGZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboggz+=	liboggz>=1.1.1
BUILDLINK_PKGSRCDIR.liboggz?=	../../multimedia/liboggz

.include "../../multimedia/libogg/buildlink3.mk"
.endif	# LIBOGGZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboggz
