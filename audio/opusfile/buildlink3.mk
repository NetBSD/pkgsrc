# $NetBSD: buildlink3.mk,v 1.3 2016/03/07 19:36:57 nros Exp $

BUILDLINK_TREE+=	opusfile

.if !defined(OPUSFILE_BUILDLINK3_MK)
OPUSFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opusfile+=	opusfile>=0.5
BUILDLINK_ABI_DEPENDS.opusfile?=	opusfile>=0.7
BUILDLINK_PKGSRCDIR.opusfile?=	../../audio/opusfile

.include "../../security/openssl/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif	# OPUSFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opusfile
