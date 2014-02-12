# $NetBSD: buildlink3.mk,v 1.27 2014/02/12 23:17:35 tron Exp $

BUILDLINK_TREE+=	ekg

.if !defined(EKG_BUILDLINK3_MK)
EKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ekg+=	ekg>=1.6
BUILDLINK_ABI_DEPENDS.ekg+=	ekg>=1.7nb8
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ekg
