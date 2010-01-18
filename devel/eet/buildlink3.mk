# $NetBSD: buildlink3.mk,v 1.14 2010/01/18 09:58:44 wiz Exp $

BUILDLINK_TREE+=	eet

.if !defined(EET_BUILDLINK3_MK)
EET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eet+=	eet>=1.0.1
BUILDLINK_ABI_DEPENDS.eet?=	eet>=1.2.3nb2
BUILDLINK_PKGSRCDIR.eet?=	../../devel/eet

.include "../../devel/eina/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EET_BUILDLINK3_MK

BUILDLINK_TREE+=	-eet
