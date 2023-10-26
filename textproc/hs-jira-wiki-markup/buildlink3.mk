# $NetBSD: buildlink3.mk,v 1.10 2023/10/26 16:34:49 pho Exp $

BUILDLINK_TREE+=	hs-jira-wiki-markup

.if !defined(HS_JIRA_WIKI_MARKUP_BUILDLINK3_MK)
HS_JIRA_WIKI_MARKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-jira-wiki-markup+=	hs-jira-wiki-markup>=1.5.1
BUILDLINK_ABI_DEPENDS.hs-jira-wiki-markup+=	hs-jira-wiki-markup>=1.5.1
BUILDLINK_PKGSRCDIR.hs-jira-wiki-markup?=	../../textproc/hs-jira-wiki-markup
.endif	# HS_JIRA_WIKI_MARKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-jira-wiki-markup
