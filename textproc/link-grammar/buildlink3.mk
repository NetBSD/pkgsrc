# $NetBSD: buildlink3.mk,v 1.5 2021/05/22 15:58:49 nia Exp $

BUILDLINK_TREE+=	link-grammar

.if !defined(LINK_GRAMMAR_BUILDLINK3_MK)
LINK_GRAMMAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.link-grammar+=	link-grammar>=4.3.4
BUILDLINK_ABI_DEPENDS.link-grammar+=	link-grammar>=5.9.1
BUILDLINK_PKGSRCDIR.link-grammar?=	../../textproc/link-grammar

.include "../../devel/argp/buildlink3.mk"
.endif # LINK_GRAMMAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-link-grammar
