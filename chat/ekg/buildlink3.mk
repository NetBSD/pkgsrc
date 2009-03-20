# $NetBSD: buildlink3.mk,v 1.20 2009/03/20 19:24:00 joerg Exp $

BUILDLINK_TREE+=	ekg

.if !defined(EKG_BUILDLINK3_MK)
EKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ekg+=	ekg>=1.6
BUILDLINK_ABI_DEPENDS.ekg+=	ekg>=1.7nb1
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ekg
