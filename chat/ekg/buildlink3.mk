# $NetBSD: buildlink3.mk,v 1.22 2010/01/17 12:02:06 wiz Exp $

BUILDLINK_TREE+=	ekg

.if !defined(EKG_BUILDLINK3_MK)
EKG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ekg+=	ekg>=1.6
BUILDLINK_ABI_DEPENDS.ekg+=	ekg>=1.7nb4
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # EKG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ekg
