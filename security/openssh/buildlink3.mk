# $NetBSD: buildlink3.mk,v 1.1 2025/06/01 08:11:47 vins Exp $

BUILDLINK_TREE+=	openssh

.if !defined(OPENSSH_BUILDLINK3_MK)
OPENSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openssh+=	openssh>=9.6
BUILDLINK_PKGSRCDIR.openssh?=	../../security/openssh

.include "../../devel/zlib/buildlink3.mk"
.endif	# OPENSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-openssh
