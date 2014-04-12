# $NetBSD: buildlink3.mk,v 1.1 2014/04/12 06:39:34 wiz Exp $

BUILDLINK_TREE+=	opusfile

.if !defined(OPUSFILE_BUILDLINK3_MK)
OPUSFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opusfile+=	opusfile>=0.5
BUILDLINK_PKGSRCDIR.opusfile?=	../../audio/opusfile

.include "../../security/openssl/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.endif	# OPUSFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opusfile
