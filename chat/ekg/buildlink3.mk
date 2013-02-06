# $NetBSD: buildlink3.mk,v 1.26 2013/02/06 23:20:53 jperkin Exp $

BUILDLINK_TREE+=	ekg

.if !defined(EKG_BUILDLINK3_MK)
EKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ekg+=	ekg>=1.6
BUILDLINK_ABI_DEPENDS.ekg+=	ekg>=1.7nb7
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ekg
