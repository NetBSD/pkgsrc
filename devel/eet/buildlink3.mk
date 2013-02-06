# $NetBSD: buildlink3.mk,v 1.18 2013/02/06 23:20:51 jperkin Exp $

BUILDLINK_TREE+=	eet

.if !defined(EET_BUILDLINK3_MK)
EET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eet+=	eet>=1.5.0
BUILDLINK_ABI_DEPENDS.eet?=	eet>=1.5.0nb3
BUILDLINK_PKGSRCDIR.eet?=	../../devel/eet

.include "../../devel/eina/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EET_BUILDLINK3_MK

BUILDLINK_TREE+=	-eet
