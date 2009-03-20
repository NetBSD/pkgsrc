# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:31 joerg Exp $

BUILDLINK_TREE+=	link-grammar

.if !defined(LINK_GRAMMAR_BUILDLINK3_MK)
LINK_GRAMMAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.link-grammar+=	link-grammar>=4.3.4
BUILDLINK_PKGSRCDIR.link-grammar?=	../../textproc/link-grammar
.endif # LINK_GRAMMAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-link-grammar
