# $NetBSD: buildlink3.mk,v 1.7 2024/02/08 23:23:36 gutteridge Exp $

BUILDLINK_TREE+=	link-grammar

.if !defined(LINK_GRAMMAR_BUILDLINK3_MK)
LINK_GRAMMAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.link-grammar+=	link-grammar>=4.3.4
BUILDLINK_ABI_DEPENDS.link-grammar+=	link-grammar>=5.10.2nb1
BUILDLINK_PKGSRCDIR.link-grammar?=	../../textproc/link-grammar

.endif # LINK_GRAMMAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-link-grammar
