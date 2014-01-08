# $NetBSD: buildlink3.mk,v 1.1 2014/01/08 23:04:43 wiz Exp $

BUILDLINK_TREE+=	libaacs

.if !defined(LIBAACS_BUILDLINK3_MK)
LIBAACS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaacs+=	libaacs>=0.7.0
BUILDLINK_PKGSRCDIR.libaacs?=	../../multimedia/libaacs

.include "../../security/libgcrypt/buildlink3.mk"
.endif	# LIBAACS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaacs
