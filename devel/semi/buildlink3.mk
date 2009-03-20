# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:29 joerg Exp $
#

BUILDLINK_TREE+=	semi

.if !defined(SEMI_BUILDLINK3_MK)
SEMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.semi+=	${EMACS_PKGNAME_PREFIX}semi>=1.14
BUILDLINK_PKGSRCDIR.semi?=	../../devel/semi

BUILDLINK_CONTENTS_FILTER.semi=	${EGREP} '.*\.el$$|.*\.elc$$'

.include "../../devel/flim/buildlink3.mk"
.endif # SEMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-semi
