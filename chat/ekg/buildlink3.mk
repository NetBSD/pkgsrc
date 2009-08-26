# $NetBSD: buildlink3.mk,v 1.21 2009/08/26 19:56:39 sno Exp $

BUILDLINK_TREE+=	ekg

.if !defined(EKG_BUILDLINK3_MK)
EKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ekg+=	ekg>=1.6
BUILDLINK_ABI_DEPENDS.ekg+=	ekg>=1.7nb3
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ekg
