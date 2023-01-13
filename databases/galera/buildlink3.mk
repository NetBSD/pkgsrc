# $NetBSD: buildlink3.mk,v 1.1 2023/01/13 16:08:03 wiz Exp $

BUILDLINK_TREE+=	galera

.if !defined(GALERA_BUILDLINK3_MK)
GALERA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.galera+=	galera>=26.4.13
BUILDLINK_PKGSRCDIR.galera?=	../../databases/galera

.include "../../security/openssl/buildlink3.mk"
.endif	# GALERA_BUILDLINK3_MK

BUILDLINK_TREE+=	-galera
