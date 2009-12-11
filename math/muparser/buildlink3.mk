# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/12/11 19:53:57 drochner Exp $

BUILDLINK_TREE+=	muparser

.if !defined(MUPARSER_BUILDLINK3_MK)
MUPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.muparser+=	muparser>=130
BUILDLINK_PKGSRCDIR.muparser?=	../../math/muparser
.endif	# MUPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-muparser
