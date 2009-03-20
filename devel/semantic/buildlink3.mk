# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:29 joerg Exp $
#

BUILDLINK_TREE+=	semantic

.if !defined(SEMANTIC_BUILDLINK3_MK)
SEMANTIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.semantic+=	${EMACS_PKGNAME_PREFIX}semantic>=10
BUILDLINK_PKGSRCDIR.semantic?=	../../devel/semantic

BUILDLINK_CONTENTS_FILTER.semantic=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # SEMANTIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-semantic
