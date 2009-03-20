# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:51 joerg Exp $

BUILDLINK_TREE+=	pnetlib

.if !defined(PNETLIB_BUILDLINK3_MK)
PNETLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pnetlib+=	pnetlib>=0.6.4
BUILDLINK_ABI_DEPENDS.pnetlib+=	pnetlib>=0.6.6nb2
BUILDLINK_PKGSRCDIR.pnetlib?=	../../lang/pnetlib

.include "../../lang/pnet/buildlink3.mk"
.endif # PNETLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pnetlib
