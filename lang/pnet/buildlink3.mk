# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:51 joerg Exp $

BUILDLINK_TREE+=	pnet

.if !defined(PNET_BUILDLINK3_MK)
PNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pnet+=	pnet>=0.8.0
BUILDLINK_PKGSRCDIR.pnet?=	../../lang/pnet

.include "../../devel/zlib/buildlink3.mk"
.endif # PNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-pnet
