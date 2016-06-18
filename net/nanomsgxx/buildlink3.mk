# $NetBSD: buildlink3.mk,v 1.1 2016/06/18 11:27:33 kamil Exp $

BUILDLINK_TREE+=	nanomsgxx

.if !defined(NANOMSGXX_BUILDLINK3_MK)
NANOMSGXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nanomsgxx+=	nanomsgxx>=0.2
BUILDLINK_PKGSRCDIR.nanomsgxx?=		../../net/nanomsgxx

.include "../../net/nanomsg/buildlink3.mk"
.endif	# NANOMSGXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-nanomsgxx
