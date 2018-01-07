# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:11 rillig Exp $
#

BUILDLINK_TREE+=	semantic

.if !defined(SEMANTIC_BUILDLINK3_MK)
SEMANTIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.semantic+=	${EMACS_PKGNAME_PREFIX}semantic>=10
BUILDLINK_PKGSRCDIR.semantic?=		../../devel/semantic

BUILDLINK_CONTENTS_FILTER.semantic=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # SEMANTIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-semantic
