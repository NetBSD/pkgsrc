# $NetBSD: buildlink3.mk,v 1.7 2023/10/24 22:08:14 wiz Exp $

BUILDLINK_TREE+=	opusfile

.if !defined(OPUSFILE_BUILDLINK3_MK)
OPUSFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opusfile+=	opusfile>=0.5
BUILDLINK_ABI_DEPENDS.opusfile?=	opusfile>=0.12nb2
BUILDLINK_PKGSRCDIR.opusfile?=		../../audio/opusfile

.include "../../security/openssl/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif	# OPUSFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opusfile
