# $NetBSD: buildlink3.mk,v 1.1 2017/10/05 19:40:35 seb Exp $

BUILDLINK_TREE+=	jsonnet

.if !defined(JSONNET_BUILDLINK3_MK)
JSONNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jsonnet+=	jsonnet>=0.9.4
BUILDLINK_PKGSRCDIR.jsonnet?=	../../devel/jsonnet
.endif	# JSONNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-jsonnet
