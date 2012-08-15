# $NetBSD: buildlink3.mk,v 1.2 2012/08/15 17:38:49 drochner Exp $

BUILDLINK_TREE+=	muparser

.if !defined(MUPARSER_BUILDLINK3_MK)
MUPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.muparser+=	muparser>=130
BUILDLINK_ABI_DEPENDS.muparser+=	muparser>=200
BUILDLINK_PKGSRCDIR.muparser?=	../../math/muparser
.endif	# MUPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-muparser
