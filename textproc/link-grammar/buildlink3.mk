# $NetBSD: buildlink3.mk,v 1.4 2021/05/22 14:15:27 nia Exp $

BUILDLINK_TREE+=	link-grammar

.if !defined(LINK_GRAMMAR_BUILDLINK3_MK)
LINK_GRAMMAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.link-grammar+=	link-grammar>=4.3.4
BUILDLINK_ABI_DEPENDS.link-grammar+=	link-grammar>=5.2.5
BUILDLINK_PKGSRCDIR.link-grammar?=	../../textproc/link-grammar

.include "../../devel/argp/buildlink3.mk"
.endif # LINK_GRAMMAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-link-grammar
