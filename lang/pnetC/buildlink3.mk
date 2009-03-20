# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:51 joerg Exp $

BUILDLINK_TREE+=	pnetC

.if !defined(PNETC_BUILDLINK3_MK)
PNETC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pnetC+=	pnetC>=0.6.4
BUILDLINK_ABI_DEPENDS.pnetC?=	pnetC>=0.6.6nb2
BUILDLINK_PKGSRCDIR.pnetC?=	../../lang/pnetC

.include "../../lang/pnet/buildlink3.mk"
.endif # PNETC_BUILDLINK3_MK

BUILDLINK_TREE+=	-pnetC
